/**
  ICMP protocol implementation
	
  Company:
    Microchip Technology Inc.

  File Name:
    icmp.c

  Summary:
     This is the implementation of ICMP version 4 stack.

  Description:
    This source file provides the implementation of the API for the ICMP Echo Ping Request/Reply.

 */

/*

©  [2015] Microchip Technology Inc. and its subsidiaries.  You may use this software 
and any derivatives exclusively with Microchip products. 
  
THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER EXPRESS, 
IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF 
NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A PARTICULAR PURPOSE, OR ITS 
INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE 
IN ANY APPLICATION. 

IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL 
OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED 
TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY 
OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S 
TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED 
THE AMOUNT OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE TERMS. 

*/

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include "network.h"
#include "tcpip_types.h"
#include "ethernet_driver.h"
#include "ipv4.h"
#include "icmp.h"
#include "ip_database.h"

/* Port 0 is N/A in both UDP and TCP */
uint16_t portUnreachable = 0;

/**
 * ICMP packet receive
 * @param ipv4_header
 * @return
 */
error_msg ICMP_Receive(ipv4Header_t *ipv4Hdr)
{
    icmpHeader_t icmpHdr;
    error_msg ret = ERROR;
    ETH_ReadBlock(&icmpHdr, sizeof(icmpHeader_t));   
    
    if(ipv4Hdr->dstIpAddress == SPECIAL_IPV4_BROADCAST_ADDRESS)
        return DEST_IP_NOT_MATCHED;
    switch(ntohs((icmpTypeCodes_t)icmpHdr.typeCode))
    {
        default:
            break;
    }

    return ret;
}


