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
#include "nm_state_machine.h"
#include "zwave_network_management_types.h"

#include "state_logging.h"

#include "unity.h"

/// Setup the test suite (called once before all test_xxx functions are called)
void suiteSetUp() {}

/// Teardown the test suite (called once after all test_xxx functions are called)
int suiteTearDown(int num_failures)
{
  return num_failures;
}

/// Called before each and every test
void setUp() {}

void test_zwave_network_management_state_name_logging_test()
{
  // clang-format off
  TEST_ASSERT_EQUAL_STRING("NM_IDLE", nm_state_name(NM_IDLE));
  TEST_ASSERT_EQUAL_STRING("NM_WAITING_FOR_ADD", nm_state_name(NM_WAITING_FOR_ADD));
  TEST_ASSERT_EQUAL_STRING("NM_NODE_FOUND", nm_state_name(NM_NODE_FOUND));
  TEST_ASSERT_EQUAL_STRING("NM_WAIT_FOR_PROTOCOL", nm_state_name(NM_WAIT_FOR_PROTOCOL));
  TEST_ASSERT_EQUAL_STRING("NM_SET_DEFAULT", nm_state_name(NM_SET_DEFAULT));
  TEST_ASSERT_EQUAL_STRING("NM_LEARN_MODE", nm_state_name(NM_LEARN_MODE));
  TEST_ASSERT_EQUAL_STRING("NM_LEARN_MODE_STARTED", nm_state_name(NM_LEARN_MODE_STARTED));
  TEST_ASSERT_EQUAL_STRING("NM_WAIT_FOR_SECURE_ADD", nm_state_name(NM_WAIT_FOR_SECURE_ADD));
  TEST_ASSERT_EQUAL_STRING("NM_WAITING_FOR_NODE_REMOVAL", nm_state_name(NM_WAITING_FOR_NODE_REMOVAL));
  TEST_ASSERT_EQUAL_STRING("NM_WAITING_FOR_FAILED_NODE_REMOVAL", nm_state_name(NM_WAITING_FOR_FAILED_NODE_REMOVAL));
  TEST_ASSERT_EQUAL_STRING("NM_WAIT_FOR_SECURE_LEARN", nm_state_name(NM_WAIT_FOR_SECURE_LEARN));
  TEST_ASSERT_EQUAL_STRING("NM_REPLACE_FAILED_REQ", nm_state_name(NM_REPLACE_FAILED_REQ));
  TEST_ASSERT_EQUAL_STRING("NM_PREPARE_SUC_INCLISION", nm_state_name(NM_PREPARE_SUC_INCLISION));
  TEST_ASSERT_EQUAL_STRING("NM_WAIT_FOR_SUC_INCLUSION", nm_state_name(NM_WAIT_FOR_SUC_INCLUSION));
  TEST_ASSERT_EQUAL_STRING("NM_PROXY_INCLUSION_WAIT_NIF", nm_state_name(NM_PROXY_INCLUSION_WAIT_NIF));
  TEST_ASSERT_EQUAL_STRING("NM_WAIT_FOR_TX_TO_SELF_DESTRUCT", nm_state_name(NM_WAIT_FOR_TX_TO_SELF_DESTRUCT));
  TEST_ASSERT_EQUAL_STRING("NM_WAIT_FOR_SELF_DESTRUCT_REMOVAL", nm_state_name(NM_WAIT_FOR_SELF_DESTRUCT_REMOVAL));
  TEST_ASSERT_EQUAL_STRING("NM_SEND_NOP", nm_state_name(NM_SEND_NOP));
  TEST_ASSERT_EQUAL_STRING("NM_FAILED_NODE_REMOVE", nm_state_name(NM_FAILED_NODE_REMOVE));
  TEST_ASSERT_EQUAL_STRING("NM_ASSIGNING_RETURN_ROUTE", nm_state_name(NM_ASSIGNING_RETURN_ROUTE));
  TEST_ASSERT_EQUAL_STRING("NM_NEIGHBOR_DISCOVERY_ONGOING", nm_state_name(NM_NEIGHBOR_DISCOVERY_ONGOING));
  TEST_ASSERT_EQUAL_STRING("Unknown", nm_state_name(NM_NEIGHBOR_DISCOVERY_ONGOING+1));
}

void test_zwave_network_management_state_event_logging_test()
{
  // clang-format off
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_LEARN_READY", nm_event_name(NM_EV_ADD_LEARN_READY));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_NODE_FOUND", nm_event_name(NM_EV_ADD_NODE_FOUND));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_CONTROLLER", nm_event_name(NM_EV_ADD_CONTROLLER));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_PROTOCOL_DONE", nm_event_name(NM_EV_ADD_PROTOCOL_DONE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_END_NODE", nm_event_name(NM_EV_ADD_END_NODE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_FAILED", nm_event_name(NM_EV_ADD_FAILED));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_NOT_PRIMARY", nm_event_name(NM_EV_ADD_NOT_PRIMARY));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_NODE_STATUS_DONE", nm_event_name(NM_EV_ADD_NODE_STATUS_DONE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_NODE_ADD", nm_event_name(NM_EV_NODE_ADD));
  TEST_ASSERT_EQUAL_STRING("NM_EV_TIMEOUT", nm_event_name(NM_EV_TIMEOUT));
  TEST_ASSERT_EQUAL_STRING("NM_EV_SECURITY_DONE", nm_event_name(NM_EV_SECURITY_DONE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_S0_STARTED", nm_event_name(NM_EV_S0_STARTED));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_SECURITY_REQ_KEYS", nm_event_name(NM_EV_ADD_SECURITY_REQ_KEYS));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_SECURITY_KEY_CHALLENGE", nm_event_name(NM_EV_ADD_SECURITY_KEY_CHALLENGE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_NODE_ADD_S2", nm_event_name(NM_EV_NODE_ADD_S2));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_SECURITY_KEYS_SET", nm_event_name(NM_EV_ADD_SECURITY_KEYS_SET));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ADD_SECURITY_DSK_SET", nm_event_name(NM_EV_ADD_SECURITY_DSK_SET));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REPLACE_FAILED_START", nm_event_name(NM_EV_REPLACE_FAILED_START));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REPLACE_FAILED_STOP", nm_event_name(NM_EV_REPLACE_FAILED_STOP));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REPLACE_FAILED_DONE", nm_event_name(NM_EV_REPLACE_FAILED_DONE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REPLACE_FAILED_FAIL", nm_event_name(NM_EV_REPLACE_FAILED_FAIL));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REPLACE_FAILED_START_S2", nm_event_name(NM_EV_REPLACE_FAILED_START_S2));
  TEST_ASSERT_EQUAL_STRING("NM_EV_LEARN_SET", nm_event_name(NM_EV_LEARN_SET));
  TEST_ASSERT_EQUAL_STRING("NM_EV_LEARN_FAILED", nm_event_name(NM_EV_LEARN_FAILED));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REQUEST_NODE_LIST", nm_event_name(NM_EV_REQUEST_NODE_LIST));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REQUEST_FAILED_NODE_LIST", nm_event_name(NM_EV_REQUEST_FAILED_NODE_LIST));
  TEST_ASSERT_EQUAL_STRING("NM_EV_PROXY_COMPLETE", nm_event_name(NM_EV_PROXY_COMPLETE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_START_PROXY_INCLUSION", nm_event_name(NM_EV_START_PROXY_INCLUSION));
  TEST_ASSERT_EQUAL_STRING("NM_EV_START_PROXY_REPLACE", nm_event_name(NM_EV_START_PROXY_REPLACE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_NODE_INFO", nm_event_name(NM_EV_NODE_INFO));
  TEST_ASSERT_EQUAL_STRING("NM_EV_FRAME_RECEIVED", nm_event_name(NM_EV_FRAME_RECEIVED));
  TEST_ASSERT_EQUAL_STRING("NM_EV_NODE_ADD_SMART_START", nm_event_name(NM_EV_NODE_ADD_SMART_START));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REMOVE_FAILED_OK", nm_event_name(NM_EV_REMOVE_FAILED_OK));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REMOVE_FAILED_FAIL", nm_event_name(NM_EV_REMOVE_FAILED_FAIL));
  TEST_ASSERT_EQUAL_STRING("NM_EV_SMART_START_ENABLE", nm_event_name(NM_EV_SMART_START_ENABLE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REMOVE_FAILED", nm_event_name(NM_EV_REMOVE_FAILED));
  TEST_ASSERT_EQUAL_STRING("NM_EV_SET_DEFAULT", nm_event_name(NM_EV_SET_DEFAULT));
  TEST_ASSERT_EQUAL_STRING("NM_EV_SET_DEFAULT_COMPLETE", nm_event_name(NM_EV_SET_DEFAULT_COMPLETE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_NODE_REMOVE", nm_event_name(NM_EV_NODE_REMOVE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_NODE_REMOVE_FAILED", nm_event_name(NM_EV_NODE_REMOVE_FAILED));
  TEST_ASSERT_EQUAL_STRING("NM_EV_NODE_REMOVE_COMPLETE", nm_event_name(NM_EV_NODE_REMOVE_COMPLETE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ABORT", nm_event_name(NM_EV_ABORT));
  TEST_ASSERT_EQUAL_STRING("NM_EV_NOP_FAIL", nm_event_name(NM_EV_NOP_FAIL));
  TEST_ASSERT_EQUAL_STRING("NM_EV_NOP_SUCCESS", nm_event_name(NM_EV_NOP_SUCCESS));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REQUEST_NODE_NEIGHBOR_REQUEST", nm_event_name(NM_EV_REQUEST_NODE_NEIGHBOR_REQUEST));
  TEST_ASSERT_EQUAL_STRING("NM_EV_REQUEST_NODE_NEIGHBOR_REQUEST_COMPLETE", nm_event_name(NM_EV_REQUEST_NODE_NEIGHBOR_REQUEST_COMPLETE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_LEARN_STARTED", nm_event_name(NM_EV_LEARN_STARTED));
  TEST_ASSERT_EQUAL_STRING("NM_EV_LEARN_DONE", nm_event_name(NM_EV_LEARN_DONE));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ASSIGN_RETURN_ROUTE_START", nm_event_name(NM_EV_ASSIGN_RETURN_ROUTE_START));
  TEST_ASSERT_EQUAL_STRING("NM_EV_ASSIGN_RETURN_ROUTE_COMPLETED", nm_event_name(NM_EV_ASSIGN_RETURN_ROUTE_COMPLETED));
  TEST_ASSERT_EQUAL_STRING("NM_EV_MAX", nm_event_name(NM_EV_MAX));
  TEST_ASSERT_EQUAL_STRING("Unknown", nm_event_name(NM_EV_MAX+1));
}