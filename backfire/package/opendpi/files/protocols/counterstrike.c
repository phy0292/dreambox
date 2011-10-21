/*
 * Counterstrike.c
 * Copyright (C) 2009-2011 by ipoque GmbH
 * 
 * This file is part of OpenDPI, an open source deep packet inspection
 * library based on the PACE technology by ipoque GmbH
 * 
 * OpenDPI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * OpenDPI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with OpenDPI.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */


#include "ipq_protocols.h"
#ifdef IPOQUE_PROTOCOL_COUNTERSTRIKE
/*static inline u8 ipoque_is_valid_counterstrike_ft_packet(const struct ipoque_packet_struct *packet)
{


｝
*/

static void ipoque_int_counterstrike_add_connection(struct ipoque_detection_module_struct
											   *ipoque_struct)
{
	ipoque_int_add_connection(ipoque_struct, IPOQUE_PROTOCOL_COUNTERSTRIKE, IPOQUE_REAL_PROTOCOL);
}

void ipoque_int_search_counterstrike_udp(struct ipoque_detection_module_struct
							*ipoque_struct)
{
	struct ipoque_packet_struct *packet = &ipoque_struct->packet;
	struct ipoque_flow_struct *flow = ipoque_struct->flow;
	// struct ipoque_id_struct *src=ipoque_struct->src;
	// struct ipoque_id_struct *dst=ipoque_struct->dst;
	if (packet->payload_packet_len >= 8 ) {
		/* 
		 * 14 BytesPattern : ff:ff:ff:ff:69:6e:66:6f:73:74:72:69:6e:67:0a:00  ....infostring.
		 * 22 BytesPattern : ff:ff:ff:ff:69:6e:66:6f:73:74:72:69:6e:67:0a:00 72 65 73 70 6f 6e 73 65 ....infostringresponse
		 * 8 BytesPattern : ff:ff:ff:ff:70:69:6e:67	....ping
		 * 16 BytesPattern : ff:ff:ff:ff:67:65:74:63:68:61:6c:6c:65:6e:67:65    ....getchallenge
		 * */
		static const char pattern_14_bytes[14] = { 0xff, 0xff, 0xff, 0xff, 0x69,
			0x6e, 0x66, 0x6f, 0x73, 0x74,
			0x72, 0x69, 0x6e, 0x67};
		static const char pattern_22_bytes[22] = { 0xff, 0xff, 0xff, 0xff, 0x69,
			0x6e, 0x66, 0x6f, 0x73, 0x74,
			0x72, 0x69, 0x6e, 0x67, 0x72, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65
		};
		static const char pattern_8_bytes[8] = { 0xff, 0xff, 0xff, 0xff, 0x70,
			0x69, 0x6e, 0x67};
		static const char pattern_16_bytes[16] = { 0xff, 0xff, 0xff, 0xff, 0x67,
			0x65, 0x74, 0x63, 0x68, 0x61,
			0x6c, 0x6c, 0x65, 0x6e, 0x67, 0x65};
		if (memcmp(&packet->payload[0], pattern_14_bytes, 14) == 0){
			IPQ_LOG_BITTORRENT(IPOQUE_PROTOCOL_COUNTERSTRIKE, ipoque_struct,
							   IPQ_LOG_DEBUG, "CounterStrike protocol detected\n");
			ipoque_int_counterstrike_add_connection(ipoque_struct);
			return;
		}
		if (memcmp(&packet->payload[0], pattern_22_bytes, 22) == 0) {
			IPQ_LOG_BITTORRENT(IPOQUE_PROTOCOL_COUNTERSTRIKE, ipoque_struct,
							   IPQ_LOG_DEBUG, "CounterStrike protocol detected\n");
			ipoque_int_counterstrike_add_connection(ipoque_struct);
			return;
		}
		if (memcmp(&packet->payload[0], pattern_8_bytes, 8) == 0) {
			IPQ_LOG_BITTORRENT(IPOQUE_PROTOCOL_COUNTERSTRIKE, ipoque_struct,
							   IPQ_LOG_DEBUG, "CounterStrike protocol detected\n");
			ipoque_int_counterstrike_add_connection(ipoque_struct);
			return;
		}
		if (memcmp(&packet->payload[0], pattern_16_bytes, 16) == 0){
			IPQ_LOG_BITTORRENT(IPOQUE_PROTOCOL_COUNTERSTRIKE, ipoque_struct,
							   IPQ_LOG_DEBUG, "CounterStrike protocol detected\n");
			ipoque_int_counterstrike_add_connection(ipoque_struct);
			return;
		}
	}

	IPQ_LOG(IPOQUE_PROTOCOL_COUNTERSTRIKE, ipoque_struct, IPQ_LOG_DEBUG, "exclude counterstrike.\n");
	IPOQUE_ADD_PROTOCOL_TO_BITMASK(flow->excluded_protocol_bitmask, IPOQUE_PROTOCOL_COUNTERSTRIKE);
}


void ipoque_search_counterstrike(struct ipoque_detection_module_struct *ipoque_struct)
{
	struct ipoque_packet_struct *packet = &ipoque_struct->packet;
	//struct ipoque_flow_struct *flow = ipoque_struct->flow;
	//struct ipoque_id_struct *src = ipoque_struct->src;
	//struct ipoque_id_struct *dst = ipoque_struct->dst;
	
	if (packet->udp != NULL) {
		ipoque_int_search_counterstrike_udp(ipoque_struct);
	}
}
#endif
