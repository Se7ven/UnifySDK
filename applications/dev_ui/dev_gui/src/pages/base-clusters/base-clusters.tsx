import React from 'react';
import { Button, Card, Col, Dropdown, DropdownButton, OverlayTrigger, Popover, Row, Spinner, Table } from 'react-bootstrap';
import * as AiIcons from 'react-icons/ai';
import * as RiIcons from 'react-icons/ri';
import * as MdIcons from 'react-icons/md'
import { BaseClustersProps, BaseClustersState, ColorPickerProps } from './base-cluster-types';
import CommandDlg from '../../components/command-dlg/command-dlg';
import ClusterAttr from '../../components/cluster-attributes/cluster-attributes';
import EditGroupDlg from '../../components/edit-group-dlg/edit-group-dlg';
import { Group } from '../groups/groups-types';
import EditableAttribute from '../../components/editable-attribute/editable-attribute';
import { ChromePicker } from 'react-color';
import { Tooltip } from '@mui/material';
import { ClusterTypes } from '../../cluster-types/cluster-types';


export class BaseClusters extends React.Component<BaseClustersProps, BaseClustersState> {
  constructor(props: BaseClustersProps) {
    super(props);
    this.state = {
      ClusterList: this.getClusterList(this.props.NodeList) || [],
      ColorPicker: {
        ShowColorPicker: false,
        ColorPickerValue: { hsv: { h: 0, s: 0, v: 0, a: 1 } },
        ColorPickerPosition: { top: 250, left: 250 },
        ProcessedItem: {}
      } as ColorPickerProps
    };

    this.changeEditGroupDlg = React.createRef();
    this.changeCommandDlg = React.createRef();
    this.changeClusterAttr = React.createRef();
  }

  changeEditGroupDlg: any;
  changeCommandDlg: any;
  changeClusterAttr: any;

  hsvToRgb = (h: number, s: number, v: number) => {
    let r = 0, g = 0, b = 0;
    let hue = h / 60;
    let c = v * s;
    let x = c * (1 - Math.abs(hue % 2 - 1));
    let m = v - c;

    switch (Math.floor(hue)) {
      case 0: r = c; g = x; b = 0; break;
      case 1: r = x; g = c; b = 0; break;
      case 2: r = 0; g = c; b = x; break;
      case 3: r = 0; g = x; b = c; break;
      case 4: r = x; g = 0; b = c; break;
      case 5: r = c; g = 0; b = x; break;
    }

    return { r: Math.round((r + m) * 255), g: Math.round((g + m) * 255), b: Math.round((b + m) * 255) };
  }

  getClusterList(nodeList: any[]) {
    if (!nodeList || !nodeList.length)
      return;
    let clusters: any[] = [];
    nodeList.forEach(i => {
      if (i.ClusterTypes.indexOf(this.props.ClusterType) > -1) {
        return Object.keys(i.ep).forEach((item: any) => {
          if (i.ep[item].Clusters?.[this.props.ClusterType]) {
            let cluster = { ...i.ep[item].Clusters[this.props.ClusterType] };
            cluster.Unid = i.Unid;
            cluster.NetworkStatus = i.NetworkStatus;
            cluster.Ep = item;
            cluster.NameAndLocation = i.ep[item].Clusters.NameAndLocation;
            clusters.push(cluster);
            if (this.props.ClusterType === ClusterTypes.ColorControl) {
              cluster.CurrentLevel = i.ep[item].Clusters[ClusterTypes.Level]?.Attributes?.CurrentLevel?.Reported;
              cluster.MaxLevel = i.ep[item].Clusters[ClusterTypes.Level]?.Attributes?.MaxLevel?.Reported;
            }
          }
        })
      }
    });
    return clusters;
  }

  updateState(nodeList: any[]) {
    this.setState({ ClusterList: this.getClusterList(nodeList) || [] });
  }

  preSendCommand(cluster: any, cmd: string) {
    let command = this.props.ClusterTypeAttrs.server.commands.find((i: { name: string; }) => i.name === cmd);
    if (!command)
      return;

    if (command && command.fields && command.fields.length) {
      this.changeCommandDlg.current.updateState(`${cluster.Unid}/${cluster.Ep}`, command, true);
    } else
      this.props.SocketServer.send(JSON.stringify(
        {
          type: "run-cluster-command",
          data: {
            Unid: `${cluster.Unid}/${cluster.Ep}`,
            ClusterType: this.props.ClusterType,
            Cmd: command.name,
            Payload: {}
          }
        }));
  }

  showClusterAttr(item: any, forceRead: boolean = false) {
    if (item.NetworkStatus !== "Offline" && item.NetworkStatus !== "Unavailable" && item.Attributes)
      this.changeClusterAttr.current.updateState(`${item.Unid}/${item.Ep}`, item.Attributes, item.SupportedCommands, forceRead)
  }

  getNodesByClusterType(nodeList: any[]) {
    return nodeList.filter(i => i.ClusterTypes.indexOf(this.props.ClusterType) > -1);
  }

  createGroup() {
    let maxIndex = 0;
    this.props.GroupList.forEach((group) => {
      maxIndex = maxIndex > group.GroupId ? maxIndex : group.GroupId;
    });

    let newGroup = {
      GroupName: "",
      GroupId: maxIndex + 1,
      NodeList: {},
      SupportedCommands: [],
      FailedNodes: [],
      UpdatingNodes: [],
      Clusters: []
    } as Group;
    this.changeEditGroupDlg.current.updateState(newGroup, this.getNodesByClusterType(this.props.NodeList), true, true);
  }

  getHashCode = (str: string) => {
    let hash = 0,
      i, chr;
    if (str.length === 0) return hash;
    for (i = 0; i < str.length; i++) {
      chr = str.charCodeAt(i);
      hash = ((hash << 5) - hash) + chr;
      hash |= 0;
    }
    return hash;
  }

  getUpdatingProperties(item: any) {
    let updatingProperties: string[] = [];
    if (item.Attributes)
      Object.keys(item.Attributes).forEach(attr => {
        let attribute = item.Attributes[attr];
        if (attribute.Desired !== undefined && attribute.Desired !== null) {
          if (Array.isArray(attribute.Desired)) {
             if(attribute.Reported === null || attribute.Reported === undefined || this.getHashCode(JSON.stringify(attribute.Reported)) !== this.getHashCode(JSON.stringify(attribute.Desired)))
            updatingProperties.push(`${attr}: ${JSON.stringify(attribute.Desired)}`)
          }
          else {
            let type = typeof (attribute.Desired);
            if (type !== "object" && attribute.Reported !== attribute.Desired)
              updatingProperties.push(`${attr}: ${attribute.Desired}`)
            else if (type === "object")
              Object.keys(attribute.Desired).forEach(i => {
                if (attribute.Reported !== undefined && attribute.Reported[i] !== undefined && (attribute.Reported[i] !== attribute.Desired[i]))
                  updatingProperties.push(`${attr}.${i}: ${attribute.Desired[i]}`)
              });
          }
        }
      });
    return updatingProperties;
  }

  handleColorPickerClose = () => {
    let picker = this.state.ColorPicker;
    picker.ShowColorPicker = false
    this.setState({ ColorPicker: picker });
  }

  handleColorChangeComplete = (color: any) => {
    if (!this.state.ColorPicker?.ProcessedItem) return;
    if (color.hsv.v !== this.state.ColorPicker.ColorPickerValue.hsv?.v) {
      this.props.SocketServer.send(JSON.stringify(
        {
          type: "run-cluster-command",
          data: {
            Unid: `${this.state.ColorPicker.ProcessedItem.Unid}/${this.state.ColorPicker.ProcessedItem.Ep}`,
            ClusterType: "Level",
            Cmd: "MoveToLevelWithOnOff",
            Payload: {
              Level: Math.round(color.hsv.v * (this.state.ColorPicker.ProcessedItem.MaxLevel ?? 255)),
              TransitionTime: 0,
              OptionsMask: {
                ExecuteIfOff: false,
                CoupleColorTempToLevel: false
              },
              OptionsOverride: {
                ExecuteIfOff: false,
                CoupleColorTempToLevel: false
              }
            }
          }
        }));
    }
    if (color.hsv.h !== this.state.ColorPicker.ColorPickerValue.hsv?.h || color.hsv.s !== this.state.ColorPicker.ColorPickerValue.hsv?.s) {
      if (!(color.hsv.s === 0 && this.state.ColorPicker.ColorPickerValue.hsv?.s === 0))
        this.props.SocketServer.send(JSON.stringify(
          {
            type: "run-cluster-command",
            data: {
              Unid: `${this.state.ColorPicker.ProcessedItem.Unid}/${this.state.ColorPicker.ProcessedItem.Ep}`,
              ClusterType: this.props.ClusterType,
              Cmd: "MoveToHueAndSaturation",
              Payload: {
                Hue: Math.round(color.hsv.h / 360 * 254),
                Saturation: Math.round(color.hsv.s * 254),
                TransitionTime: 0,
                OptionsMask: { ExecuteIfOff: false },
                OptionsOverride: { ExecuteIfOff: false }
              }
            }
          }));
    }
    let picker = this.state.ColorPicker;
    picker.ColorPickerValue = color;
    this.setState({ ColorPicker: picker });
  };

  getColorPicker = (item: any) => {
    let hue = item.Attributes?.CurrentHue?.Reported === undefined ? 0 : Math.round(item.Attributes.CurrentHue.Reported / 254 * 360);
    let saturation = item.Attributes?.CurrentSaturation?.Reported === undefined ? 0 : item.Attributes.CurrentSaturation.Reported / 254;
    let value = (item.CurrentLevel ?? item.MaxLevel ?? 255) / (item.MaxLevel ?? 255);
    let rgb = this.hsvToRgb(hue, saturation, value);
    return <Tooltip title="Set Hue, Saturation and Level">
      <span className="pointer">
        <MdIcons.MdInvertColors color={`rgb(${rgb.r} ${rgb.g} ${rgb.b})`} onClick={(event: any) => {
          let picker = this.state.ColorPicker;
          picker.ShowColorPicker = !this.state.ColorPicker.ShowColorPicker;
          picker.ColorPickerPosition = { top: event.clientY, left: event.clientX };
          picker.ProcessedItem = item;
          picker.ColorPickerValue.hsv = { h: hue, s: saturation, v: value, a: 1 };
          this.setState({ ColorPicker: picker })
        }} />
      </span>
    </Tooltip>
  }

  actionsList = (item: any) => {
    let commands = item.SupportedCommands && item.SupportedCommands.filter((cmd: any) => cmd !== "WriteAttributes" && cmd !== "AddScene")
    return commands && commands.length
      ? <DropdownButton menuAlign={'right'} variant="outline-primary" title="Commands" size="sm" className={`float-left`} disabled={item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable"}>
        {commands.map((cmd: string, cmdIndex: number) => {
          return (
            <Dropdown.Item key={cmdIndex} onClick={this.preSendCommand.bind(this, item, cmd)}> {cmd.charAt(0).toUpperCase() + cmd.slice(1)}</Dropdown.Item>
          )
        })
        }
      </DropdownButton>
      : <></>


  }

  render() {
    let attrNames: string[] = this.props.ClusterViewOverrides?.ViewTable?.map(i => i.Name) || [];
    if (!attrNames.length && this.props.ClusterTypeAttrs.server.attributes && this.state.ClusterList && this.state.ClusterList.length) {
      let attrs = new Set<string>();
      this.state.ClusterList?.forEach((i: any) => {
        if (i.Attributes) {
          Object.keys(i.Attributes).forEach(attr => {
            attrs.add(attr);
          });
          return;
        }
      });
      for (let index = 0; index < this.props.ClusterTypeAttrs.server.attributes.length; index++) {
        if (attrs.has(this.props.ClusterTypeAttrs.server.attributes[index].name)) {
          attrNames.push(this.props.ClusterTypeAttrs.server.attributes[index].name)
          if (attrNames.length >= 5)
            break;
        }

      }
    }
    let isMobile = /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent);
    return (
      <>
        <h3 hidden={!this.props.ShowTitle}>{this.props.ClusterViewOverrides?.NavbarItem?.title || this.props.ClusterType}</h3>
        <Row hidden={!this.props.IsConnected} >
          <Col xs={12}>
            <Button variant="outline-primary" className="float-left margin-b-10" onClick={() => this.createGroup()}>Create Group</Button>
          </Col>
        </Row>
        {(!this.state.ClusterList || !this.state.ClusterList.length)
          ? <Row>
            <Col xs={12} className="text-center">
              <span className="no-content">No Content</span>
            </Col>
          </Row>
          : (isMobile
            ? <div className='table-content'>
              {
                this.state.ClusterList.map((item, index) => {
                  let updatingProperties: string[] = this.getUpdatingProperties(item);
                  let className = item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable" ? "disabled" : "";
                  let popover = (
                    <Popover id={`${item.Unid}/${item.Ep}`} className="popover-l">
                      <Popover.Title as="h3">Waiting for update next properties</Popover.Title>
                      <Popover.Content>
                        {updatingProperties.join(', \n')}
                      </Popover.Content>
                    </Popover>
                  );
                  return (
                    <Tooltip key={index} title={(item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable") ? "Node is Offline" : ""}>
                      <Card key={index} className="inline margin-v-10">
                        <Card.Header className='flex'>
                          <div className={`col-sm-6 ${className}`}>
                            <span hidden={item.NetworkStatus !== "Offline" || item.NetworkStatus === "Unavailable"} className="margin-h-5"><RiIcons.RiWifiOffLine color="red" /></span>
                            <b><EditableAttribute Node={item} EpName={item.Ep} Cluster={item.NameAndLocation} ClusterName="NameAndLocation" FieldName="Name" SocketServer={this.props.SocketServer} ReplaceNameWithUnid={true} Disabled={item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable"} /></b></div>
                          <div className="col-sm-6 float-right">
                            {this.actionsList(item)}
                            <Tooltip title="Customize Attributes">
                              <span className={(item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable" || !item.Attributes) ? "margin-h-5 icon cursor-default disabled float-right" : "margin-h-5 icon float-right"}>
                                <AiIcons.AiOutlineTool onClick={() => this.showClusterAttr(item)} />
                              </span>
                            </Tooltip>
                            <Tooltip title="Force Read Attributes">
                              <span className={(item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable" || !item.Attributes) ? "margin-h-5 icon cursor-default disabled float-right" : "margin-h-5 icon float-right"}>
                                <MdIcons.MdOutlineReadMore onClick={() => this.showClusterAttr(item, true)} />
                              </span>
                            </Tooltip>
                            {this.props.ClusterViewOverrides?.CustomActions && this.props.ClusterViewOverrides?.CustomActions(item.Unid, item.Ep)}
                            <OverlayTrigger trigger={['hover', 'focus']} placement="right" overlay={popover}>
                              <Spinner hidden={!updatingProperties.length || item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable"} as="span" animation="border" size="sm" variant="primary" className='float-right margin-t-10' />
                            </OverlayTrigger>
                          </div>
                        </Card.Header>
                        <Card.Body className={className}>
                          <div className='col-sm-12'>
                            {this.props.ClusterViewOverrides?.ViewTable?.map((column, colIndex) => {
                              return <div className="col-sm-6 inline" key={colIndex}><b><i>{column.Name}: </i></b>{column.Value(item, this.getColorPicker)}</div>
                            })
                              || attrNames.map((column, colIndex) => {
                                return <div className="col-sm-6 inline" key={colIndex}><b><i>{column}: </i></b>{item.Attributes && item.Attributes[column] && item.Attributes[column].Reported !== null && item.Attributes[column].Reported !== undefined ? JSON.stringify(item.Attributes[column].Reported) : "-"}</div>
                              })
                            }
                          </div>
                        </Card.Body>
                      </Card>
                    </Tooltip>
                  );
                })}
            </div>
            : <Table striped hover className='vertical-middle'>
              <thead>
                <tr>
                  <th>Name</th>
                  {attrNames.map((item, index) => {
                    return <th key={index}>{item}</th>
                  })}
                  <th className="wd-40px">&nbsp;</th>
                  <th>Supported Commands</th>
                  <th></th>
                </tr>
              </thead>
              <tbody>
                {this.state.ClusterList.map((item, index) => {
                  let updatingProperties: string[] = this.getUpdatingProperties(item);
                  let popover = (
                    <Popover id={`${item.Unid}/${item.Ep}`} className="popover-l">
                      <Popover.Title as="h3">Waiting for update next properties</Popover.Title>
                      <Popover.Content>
                        {updatingProperties.join(', \n')}
                      </Popover.Content>
                    </Popover>
                  );
                  return <Tooltip key={index} title={(item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable") ? "Node is Offline" : ""}>
                    <tr className={(item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable") ? "disabled" : ""}>
                      <td>
                        <span hidden={item.NetworkStatus !== "Offline" || item.NetworkStatus === "Unavailable"} className="margin-h-5"><RiIcons.RiWifiOffLine color="red" /></span>
                        <EditableAttribute Node={item} EpName={item.Ep} Cluster={item.NameAndLocation} ClusterName="NameAndLocation" FieldName="Name" SocketServer={this.props.SocketServer} ReplaceNameWithUnid={true} Disabled={item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable"} />
                      </td>
                      {this.props.ClusterViewOverrides?.ViewTable?.map((column, colIndex) => {
                        return <td key={colIndex}>{column.Value(item, this.getColorPicker)}</td>
                      })
                        || attrNames.map((column, colIndex) => {
                          return <td key={colIndex}>{item.Attributes && item.Attributes[column] && item.Attributes[column].Reported !== null && item.Attributes[column].Reported !== undefined ? JSON.stringify(item.Attributes[column].Reported) : "-"}</td>
                        })
                      }
                      <td>
                        <OverlayTrigger trigger={['hover', 'focus']} placement="right" overlay={popover}>
                          <Spinner hidden={!updatingProperties.length || item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable"} as="span" animation="border" size="sm" variant="primary" />
                        </OverlayTrigger>
                      </td>
                      <td>{this.actionsList(item)}</td>
                      <td className="text-center">
                        <Tooltip title="Customize Attributes">
                          <span className={(item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable" || !item.Attributes) ? "margin-h-5 icon cursor-default disabled" : "margin-h-5 icon"}>
                            <AiIcons.AiOutlineTool onClick={() => this.showClusterAttr(item)} />
                          </span>
                        </Tooltip>
                        <Tooltip title="Force Read Attributes">
                          <span className={(item.NetworkStatus === "Offline" || item.NetworkStatus === "Unavailable" || !item.Attributes) ? "margin-h-5 icon cursor-default disabled " : "margin-h-5 icon"}>
                            <MdIcons.MdOutlineReadMore onClick={() => this.showClusterAttr(item, true)} />
                          </span>
                        </Tooltip>
                        {this.props.ClusterViewOverrides?.CustomActions && this.props.ClusterViewOverrides?.CustomActions(item.Unid, item.Ep)}
                      </td>
                    </tr>
                  </Tooltip>
                })}
              </tbody>
            </Table>
          )
        }

        <div className="color-picker-container" hidden={!this.state.ColorPicker.ShowColorPicker} style={{
          top: this.state.ColorPicker.ColorPickerPosition.top - 96,
          left: this.state.ColorPicker.ColorPickerPosition.left - 34
        }}>
          <div className='cover' onClick={this.handleColorPickerClose} />
          <ChromePicker disableAlpha={true} color={this.state.ColorPicker.ColorPickerValue.hsv} onChangeComplete={this.handleColorChangeComplete} />
        </div>

        <EditGroupDlg ref={this.changeEditGroupDlg}
          SocketServer={this.props.SocketServer}
          NodeList={this.getNodesByClusterType(this.props.NodeList)} />

        <CommandDlg ref={this.changeCommandDlg}
          SocketServer={this.props.SocketServer}
          ClusterType={this.props.ClusterType} />

        <ClusterAttr ref={this.changeClusterAttr}
          SocketServer={this.props.SocketServer}
          ClusterType={this.props.ClusterType}
          ClusterAttr={this.props.ClusterTypeAttrs.server.attributes} />
      </>
    )
  };
}

export default BaseClusters;