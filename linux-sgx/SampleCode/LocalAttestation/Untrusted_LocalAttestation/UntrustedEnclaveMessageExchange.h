/*
 * Copyright (C) 2011-2018 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#include "sgx_eid.h"
#include "error_codes.h"
#include "datatypes.h"
#include "sgx_urts.h"
#include "dh_session_protocol.h"
#include "sgx_dh.h"
#include <cstddef>


#ifndef ULOCALATTESTATION_H_
#define ULOCALATTESTATION_H_

#ifdef __cplusplus
extern "C" {
#endif

sgx_status_t Enclave1_session_request(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg1_t* dh_msg1, uint32_t* session_id);
sgx_status_t Enclave1_exchange_report(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg2_t* dh_msg2, sgx_dh_msg3_t* dh_msg3, uint32_t session_id);
sgx_status_t Enclave1_generate_response(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id, secure_message_t* req_message, size_t req_message_size, size_t max_payload_size, secure_message_t* resp_message, size_t resp_message_size);
sgx_status_t Enclave1_end_session(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id);

sgx_status_t Enclave2_session_request(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg1_t* dh_msg1, uint32_t* session_id);
sgx_status_t Enclave2_exchange_report(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg2_t* dh_msg2, sgx_dh_msg3_t* dh_msg3, uint32_t session_id);
sgx_status_t Enclave2_generate_response(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id, secure_message_t* req_message, size_t req_message_size, size_t max_payload_size, secure_message_t* resp_message, size_t resp_message_size);
sgx_status_t Enclave2_end_session(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id);

sgx_status_t Enclave3_session_request(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg1_t* dh_msg1, uint32_t* session_id);
sgx_status_t Enclave3_exchange_report(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg2_t* dh_msg2, sgx_dh_msg3_t* dh_msg3, uint32_t session_id);
sgx_status_t Enclave3_generate_response(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id, secure_message_t* req_message, size_t req_message_size, size_t max_payload_size, secure_message_t* resp_message, size_t resp_message_size);
sgx_status_t Enclave3_end_session(sgx_enclave_id_t eid, uint32_t* retval, sgx_enclave_id_t src_enclave_id);

uint32_t session_request_ocall(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, sgx_dh_msg1_t* dh_msg1, uint32_t* session_id);
uint32_t exchange_report_ocall(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, sgx_dh_msg2_t* dh_msg2, sgx_dh_msg3_t* dh_msg3, uint32_t session_id);
uint32_t send_request_ocall(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, secure_message_t* req_message, size_t req_message_size, size_t max_payload_size, secure_message_t* resp_message, size_t resp_message_size);
uint32_t end_session_ocall(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id);

#ifdef __cplusplus
}
#endif

#endif
