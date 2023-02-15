/******************************************************************************
 * # License
 * <b>Copyright 2022 Silicon Laboratories Inc. www.silabs.com</b>
 ******************************************************************************
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 *****************************************************************************/

// clang-format off
// This file is generated by ZCL Advanced Platform generator. Please don't edit manually.

/**
 * @defgroup dotdot_cluster_id_definitions DotDot Cluster ID definitions
 * @ingroup unify_components
 * @brief Header with Cluster ID definitions
 *
 * Cluster identifier defines (e.g. OnOff ID is 0x0006)
 *
 * @{
 */

#ifndef DOTDOT_CLUSTER_ID_DEFINITIONS_H
#define DOTDOT_CLUSTER_ID_DEFINITIONS_H

#include "uic_typedefs.h"

// Special value to use when the Cluster ID cannot be found.
#define DOTDOT_INVALID_CLUSTER_ID ((dotdot_cluster_id_t){0xFFFF})



// Definitions for cluster: Basic
#define DOTDOT_BASIC_CLUSTER_ID ((dotdot_cluster_id_t)0x0)


// Definitions for cluster: PowerConfiguration
#define DOTDOT_POWER_CONFIGURATION_CLUSTER_ID ((dotdot_cluster_id_t)0x1)


// Definitions for cluster: DeviceTemperatureConfiguration
#define DOTDOT_DEVICE_TEMPERATURE_CONFIGURATION_CLUSTER_ID ((dotdot_cluster_id_t)0x2)


// Definitions for cluster: Identify
#define DOTDOT_IDENTIFY_CLUSTER_ID ((dotdot_cluster_id_t)0x3)


// Definitions for cluster: Groups
#define DOTDOT_GROUPS_CLUSTER_ID ((dotdot_cluster_id_t)0x4)


// Definitions for cluster: Scenes
#define DOTDOT_SCENES_CLUSTER_ID ((dotdot_cluster_id_t)0x5)


// Definitions for cluster: OnOff
#define DOTDOT_ON_OFF_CLUSTER_ID ((dotdot_cluster_id_t)0x6)


// Definitions for cluster: Level
#define DOTDOT_LEVEL_CLUSTER_ID ((dotdot_cluster_id_t)0x8)


// Definitions for cluster: Alarms
#define DOTDOT_ALARMS_CLUSTER_ID ((dotdot_cluster_id_t)0x9)


// Definitions for cluster: Time
#define DOTDOT_TIME_CLUSTER_ID ((dotdot_cluster_id_t)0xA)


// Definitions for cluster: Commissioning
#define DOTDOT_COMMISSIONING_CLUSTER_ID ((dotdot_cluster_id_t)0x15)


// Definitions for cluster: OTAUpgrade
#define DOTDOT_OTA_UPGRADE_CLUSTER_ID ((dotdot_cluster_id_t)0x19)


// Definitions for cluster: PollControl
#define DOTDOT_POLL_CONTROL_CLUSTER_ID ((dotdot_cluster_id_t)0x20)


// Definitions for cluster: ShadeConfiguration
#define DOTDOT_SHADE_CONFIGURATION_CLUSTER_ID ((dotdot_cluster_id_t)0x100)


// Definitions for cluster: DoorLock
#define DOTDOT_DOOR_LOCK_CLUSTER_ID ((dotdot_cluster_id_t)0x101)


// Definitions for cluster: WindowCovering
#define DOTDOT_WINDOW_COVERING_CLUSTER_ID ((dotdot_cluster_id_t)0x102)


// Definitions for cluster: BarrierControl
#define DOTDOT_BARRIER_CONTROL_CLUSTER_ID ((dotdot_cluster_id_t)0x103)


// Definitions for cluster: PumpConfigurationAndControl
#define DOTDOT_PUMP_CONFIGURATION_AND_CONTROL_CLUSTER_ID ((dotdot_cluster_id_t)0x200)


// Definitions for cluster: Thermostat
#define DOTDOT_THERMOSTAT_CLUSTER_ID ((dotdot_cluster_id_t)0x201)


// Definitions for cluster: FanControl
#define DOTDOT_FAN_CONTROL_CLUSTER_ID ((dotdot_cluster_id_t)0x202)


// Definitions for cluster: DehumidificationControl
#define DOTDOT_DEHUMIDIFICATION_CONTROL_CLUSTER_ID ((dotdot_cluster_id_t)0x203)


// Definitions for cluster: ThermostatUserInterfaceConfiguration
#define DOTDOT_THERMOSTAT_USER_INTERFACE_CONFIGURATION_CLUSTER_ID ((dotdot_cluster_id_t)0x204)


// Definitions for cluster: ColorControl
#define DOTDOT_COLOR_CONTROL_CLUSTER_ID ((dotdot_cluster_id_t)0x300)


// Definitions for cluster: BallastConfiguration
#define DOTDOT_BALLAST_CONFIGURATION_CLUSTER_ID ((dotdot_cluster_id_t)0x301)


// Definitions for cluster: IlluminanceMeasurement
#define DOTDOT_ILLUMINANCE_MEASUREMENT_CLUSTER_ID ((dotdot_cluster_id_t)0x400)


// Definitions for cluster: IlluminanceLevelSensing
#define DOTDOT_ILLUMINANCE_LEVEL_SENSING_CLUSTER_ID ((dotdot_cluster_id_t)0x401)


// Definitions for cluster: TemperatureMeasurement
#define DOTDOT_TEMPERATURE_MEASUREMENT_CLUSTER_ID ((dotdot_cluster_id_t)0x402)


// Definitions for cluster: PressureMeasurement
#define DOTDOT_PRESSURE_MEASUREMENT_CLUSTER_ID ((dotdot_cluster_id_t)0x403)


// Definitions for cluster: FlowMeasurement
#define DOTDOT_FLOW_MEASUREMENT_CLUSTER_ID ((dotdot_cluster_id_t)0x404)


// Definitions for cluster: RelativityHumidity
#define DOTDOT_RELATIVITY_HUMIDITY_CLUSTER_ID ((dotdot_cluster_id_t)0x405)


// Definitions for cluster: OccupancySensing
#define DOTDOT_OCCUPANCY_SENSING_CLUSTER_ID ((dotdot_cluster_id_t)0x406)


// Definitions for cluster: PhMeasurement
#define DOTDOT_PH_MEASUREMENT_CLUSTER_ID ((dotdot_cluster_id_t)0x409)


// Definitions for cluster: ElectricalConductivityMeasurement
#define DOTDOT_ELECTRICAL_CONDUCTIVITY_MEASUREMENT_CLUSTER_ID ((dotdot_cluster_id_t)0x40A)


// Definitions for cluster: WindSpeedMeasurement
#define DOTDOT_WIND_SPEED_MEASUREMENT_CLUSTER_ID ((dotdot_cluster_id_t)0x40B)


// Definitions for cluster: CarbonMonoxide
#define DOTDOT_CARBON_MONOXIDE_CLUSTER_ID ((dotdot_cluster_id_t)0x40C)


// Definitions for cluster: IASZone
#define DOTDOT_IAS_ZONE_CLUSTER_ID ((dotdot_cluster_id_t)0x500)


// Definitions for cluster: IASACE
#define DOTDOT_IASACE_CLUSTER_ID ((dotdot_cluster_id_t)0x501)


// Definitions for cluster: IASWD
#define DOTDOT_IASWD_CLUSTER_ID ((dotdot_cluster_id_t)0x502)


// Definitions for cluster: Metering
#define DOTDOT_METERING_CLUSTER_ID ((dotdot_cluster_id_t)0x702)


// Definitions for cluster: ElectricalMeasurement
#define DOTDOT_ELECTRICAL_MEASUREMENT_CLUSTER_ID ((dotdot_cluster_id_t)0xB04)


// Definitions for cluster: Diagnostics
#define DOTDOT_DIAGNOSTICS_CLUSTER_ID ((dotdot_cluster_id_t)0xB05)


// Definitions for cluster: ProtocolController-RFTelemetry
#define DOTDOT_PROTOCOL_CONTROLLER_RF_TELEMETRY_CLUSTER_ID ((dotdot_cluster_id_t)0xFD01)


// Definitions for cluster: State
#define DOTDOT_STATE_CLUSTER_ID ((dotdot_cluster_id_t)0xFD02)


// Definitions for cluster: Binding
#define DOTDOT_BINDING_CLUSTER_ID ((dotdot_cluster_id_t)0xFD03)


// Definitions for cluster: SystemMetrics
#define DOTDOT_SYSTEM_METRICS_CLUSTER_ID ((dotdot_cluster_id_t)0xFD04)


// Definitions for cluster: ApplicationMonitoring
#define DOTDOT_APPLICATION_MONITORING_CLUSTER_ID ((dotdot_cluster_id_t)0xFD05)


// Definitions for cluster: NameAndLocation
#define DOTDOT_NAME_AND_LOCATION_CLUSTER_ID ((dotdot_cluster_id_t)0xFD06)


// Definitions for cluster: ConfigurationParameters
#define DOTDOT_CONFIGURATION_PARAMETERS_CLUSTER_ID ((dotdot_cluster_id_t)0xFD07)


// Definitions for cluster: AoXLocator
#define DOTDOT_AOX_LOCATOR_CLUSTER_ID ((dotdot_cluster_id_t)0xFD10)


// Definitions for cluster: AoXPositionEstimation
#define DOTDOT_AOX_POSITION_ESTIMATION_CLUSTER_ID ((dotdot_cluster_id_t)0xFD11)


// Definitions for cluster: ProtocolController-NetworkManagement
#define DOTDOT_PROTOCOL_CONTROLLER_NETWORK_MANAGEMENT_CLUSTER_ID ((dotdot_cluster_id_t)0xFD12)


#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Get the cluster name based on the cluster ID.
 *
 * @param cluster_id        Cluster ID, for example 0x0006 or DOTDOT_ON_OFF_CLUSTER_ID
 * @returns const char*      Name of the cluster ("OnOff"). "Unknown" if it does not exist.
 */
const char* uic_dotdot_get_cluster_name(dotdot_cluster_id_t cluster_id);

/**
 * @brief Get the cluster name based on the cluster ID.
 *
 * @param cluster_name          Cluster Name, for example "Level"
 * @returns dotdot_cluster_id_t  ID of the cluster (e.g. 0x0006),
 *          DOTDOT_INVALID_CLUSTER_ID if it does not exist.
 */
dotdot_cluster_id_t uic_dotdot_get_cluster_id(const char* cluster_name);

#ifdef __cplusplus
}
#endif

#endif  //DOTDOT_CLUSTER_ID_DEFINITIONS_H
/** @} end dotdot_cluster_id_definitions */
