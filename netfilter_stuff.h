/*
 * =====================================================================================
 *
 *       Filename:  netfilter_stuff.h
 *
 *    Description:  netilter stuff header
 *
 *        Version:  1.0
 *        Created:  06/07/2019 09:44:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef NETFILTER_STUFF_H
#define NETFILTER_STUFF_H

#include <linux/types.h>
#include <net/ip.h>
#include <net/tcp.h>
// Structs to read a manipulate a raw TCP packet
typedef uint32_t addr_t;
typedef uint16_t port_t;

#define METADATA_SIZE 20
#pragma pack(push, 1)
typedef struct {
	uint32_t padding; // All zeroes
	uint8_t  exp_opt; // Should be experimental option assigned by IANA
	uint8_t  exp_opt_len;
	uint16_t exp_opt_id;
	//uint16_t exp_opt_exid; // ExID for experimental option
	uint32_t enc_client_ip;
	uint32_t victim_server_ip;
	uint32_t enc_key_id;
} pkt_meta;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
	struct iphdr ipv4_header;
	struct tcphdr tcp_header;
} full_tcp_pkt_t;
#pragma pack(pop)

#endif
