/*
 * HF.c
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
#ifdef IPOQUE_PROTOCOL_HF
/*static inline u8 ipoque_is_valid_hf_ft_packet(const struct ipoque_packet_struct *packet)
{


｝
*/

static void ipoque_int_hf_add_connection(struct ipoque_detection_module_struct
											   *ipoque_struct)
{
	ipoque_int_add_connection(ipoque_struct, IPOQUE_PROTOCOL_HF, IPOQUE_REAL_PROTOCOL);
}

void ipoque_int_search_hf_udp(struct ipoque_detection_module_struct
							*ipoque_struct)
{
	struct ipoque_packet_struct *packet = &ipoque_struct->packet;
	struct ipoque_flow_struct *flow = ipoque_struct->flow;
	u16 hf_2;
	// struct ipoque_id_struct *src=ipoque_struct->src;
	// struct ipoque_id_struct *dst=ipoque_struct->dst;
			if (packet->payload_packet_len == 40  && get_l16(packet->payload, 0) == packet->payload_packet_len )
				{
				if ( ntohs(get_u16(packet->payload, 2)) == 0x0000 && ntohs(get_u16(packet->payload, 4)) == 0x0200 && ntohs(get_u16(packet->payload, 6)) == 0x0600)
					{
					IPQ_LOG(IPOQUE_PROTOCOL_HF, ipoque_struct, IPQ_LOG_DEBUG,
							"found hf.\n");
					ipoque_int_hf_add_connection(ipoque_struct);
					return;
					}
				}
				//房间测速
				if ( ntohs(get_u16(packet->payload, 2)) == 0x0000 && ntohs(get_u16(packet->payload, 4)) == 0x1010 && ntohs(get_u16(packet->payload, 6)) == 0x0000)
					{
					IPQ_LOG(IPOQUE_PROTOCOL_HF, ipoque_struct, IPQ_LOG_DEBUG,
							"found hf.\n");
					ipoque_int_hf_add_connection(ipoque_struct);
					return;
					}
				
			//游戏中 
			if (packet->payload_packet_len > 8  && get_l16(packet->payload, 0) == packet->payload_packet_len )
				{
				hf_2 = ntohs(get_u16(packet->payload, 2));
				switch(hf_2)
					{
					case 0x0410:
					case 0x0210:
					case 0x0310:
					case 0x0910:
					case 0x0140:
					case 0x0240:
					case 0x0340:
						flow->hf_stage++;
						break;
					default:
						break;
					}
				if(flow->hf_stage == 3){
						IPQ_LOG(IPOQUE_PROTOCOL_HF, ipoque_struct, IPQ_LOG_DEBUG,
								"found hf.\n");
						ipoque_int_hf_add_connection(ipoque_struct);
						return;
						}
				return;
				}
//	IPQ_LOG(IPOQUE_PROTOCOL_HF, ipoque_struct, IPQ_LOG_DEBUG, "exclude hf.\n");
//	IPOQUE_ADD_PROTOCOL_TO_BITMASK(flow->excluded_protocol_bitmask, IPOQUE_PROTOCOL_HF);
}
void ipoque_int_search_hf_tcp(struct ipoque_detection_module_struct
							*ipoque_struct)
{
	struct ipoque_packet_struct *packet = &ipoque_struct->packet;
	struct ipoque_flow_struct *flow = ipoque_struct->flow;

		if ( get_l16(packet->payload, 0) == packet->payload_packet_len)
			{
			if ( get_u16(packet->payload, 2) == 0x0000 && (get_u16(packet->payload, 4) == htons(0x0a00) || get_u16(packet->payload, 4) == htons(0x0400) || get_u16(packet->payload, 4) == htons(0x0100) || get_u16(packet->payload, 4) == htons(0xaa00) || get_u16(packet->payload, 4) == htons(0x0200) || get_u16(packet->payload, 4) == htons(0x0300)) && (get_u16(packet->payload, 6) == htons(0x0300) || get_u16(packet->payload, 6) == htons(0x0100))&& (get_u16(packet->payload, 8) == htons(0x0300) || get_u16(packet->payload, 8) == htons(0x0400) || get_u16(packet->payload, 8) == htons(0x0900)))
				{
/*				flow->hf_stage++;
				if (flow->hf_stage == 3){
					IPQ_LOG(IPOQUE_PROTOCOL_HF, ipoque_struct, IPQ_LOG_DEBUG,
							"found hf.\n");
					ipoque_int_hf_add_connection(ipoque_struct);
					return;
					}
*/
				IPQ_LOG(IPOQUE_PROTOCOL_HF, ipoque_struct, IPQ_LOG_DEBUG,
						"found hf.\n");
				ipoque_int_hf_add_connection(ipoque_struct);
				return;
				}
			if ( get_u16(packet->payload, 2) == 0x0000 && (get_u16(packet->payload, 4) == htons(0x0100) || get_u16(packet->payload, 4) == htons(0xaa00) || get_u16(packet->payload, 4) == htons(0x0400) || get_u16(packet->payload, 4) == htons(0x0300) || get_u16(packet->payload, 4) == htons(0x1500) || get_u16(packet->payload, 4) == htons(0x1600) || get_u16(packet->payload, 4) == htons(0xab00) || get_u16(packet->payload, 4) == htons(0x1900)) && (get_u16(packet->payload, 6) == htons(0x0100) || get_u16(packet->payload, 6) == htons(0x0900)))
				{
/*				flow->hf_stage++;
				if (flow->hf_stage == 3){
					IPQ_LOG(IPOQUE_PROTOCOL_HF, ipoque_struct, IPQ_LOG_DEBUG,
							"found hf.\n");
					ipoque_int_hf_add_connection(ipoque_struct);
					return;
					}
*/
				IPQ_LOG(IPOQUE_PROTOCOL_HF, ipoque_struct, IPQ_LOG_DEBUG,
						"found hf.\n");
				ipoque_int_hf_add_connection(ipoque_struct);
				return;
				}

			}
//	IPQ_LOG(IPOQUE_PROTOCOL_HF, ipoque_struct, IPQ_LOG_DEBUG, "exclude hf.\n");
//	IPOQUE_ADD_PROTOCOL_TO_BITMASK(flow->excluded_protocol_bitmask, IPOQUE_PROTOCOL_HF);
}

void ipoque_search_hf(struct ipoque_detection_module_struct *ipoque_struct)
{
	struct ipoque_packet_struct *packet = &ipoque_struct->packet;
	//struct ipoque_flow_struct *flow = ipoque_struct->flow;
	//struct ipoque_id_struct *src = ipoque_struct->src;
	//struct ipoque_id_struct *dst = ipoque_struct->dst;
	
	if (packet->tcp != NULL && packet->payload_packet_len != 0) {
		ipoque_int_search_hf_tcp(ipoque_struct);
	} else if (packet->udp != NULL) {
		ipoque_int_search_hf_udp(ipoque_struct);
	}
}
#endif
