/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1992-1996  Microsoft Corporation

Module Name:

    svcguid.h

Abstract:

    Defines GUIDs for well-known services including:

        HOSTNAME
        RFC 1060 (Assigned Numbers) from IANA (All TCP/IP Services)
        NetWare services

Created:

    May 8, 1994

Revision History:

--*/

#ifndef _SVCGUID_
#define _SVCGUID_

#include  <basetyps.h>

//
// HOSTNAME--special GUID which refers to the name of a host as opposed
// to any particular service on that host.
//

#define SVCID_HOSTNAME { 0x0002a800, 0, 0, { 0xC0,0,0,0,0,0,0,0x46 } }

//
// Macros for defining and testing TCP and UDP GUIDs from a well-known 
// port.  
//

#define SVCID_TCP(_Port) \
             { (0x0009 << 16) | (_Port), 0, 0, { 0xC0,0,0,0,0,0,0,0x46 } }

#define IS_SVCID_TCP(_g) \
             ( ((((_g)->Data1) & 0xFFFF0000) == 0x00090000) && \
               (((_g)->Data2) == 0) &&                       \
               (((_g)->Data3) == 0) &&                       \
               (((_g)->Data4[0]) == 0xC0) &&                 \
               (((_g)->Data4[1]) == 0) &&                    \
               (((_g)->Data4[2]) == 0) &&                    \
               (((_g)->Data4[3]) == 0) &&                    \
               (((_g)->Data4[4]) == 0) &&                    \
               (((_g)->Data4[5]) == 0) &&                    \
               (((_g)->Data4[6]) == 0) &&                    \
               (((_g)->Data4[7]) == 0x46) )

#define PORT_FROM_SVCID_TCP(_g) \
               ((WORD)(_g->Data1 & 0xFFFF))

#define SET_TCP_SVCID(_g,_Port) {                            \
               (_g)->Data1 = (0x0009 << 16 ) | (_Port);      \
               (_g)->Data2 = 0;                              \
               (_g)->Data3 = 0;                              \
               (_g)->Data4[0] = 0xC0;                        \
               (_g)->Data4[1] = 0x0;                         \
               (_g)->Data4[2] = 0x0;                         \
               (_g)->Data4[3] = 0x0;                         \
               (_g)->Data4[4] = 0x0;                         \
               (_g)->Data4[5] = 0x0;                         \
               (_g)->Data4[6] = 0x0;                         \
               (_g)->Data4[7] = 0x46; }

#define SVCID_UDP(_Port) \
             { (0x000A << 16) | (_Port), 0, 0, { 0xC0,0,0,0,0,0,0,0x46 } }

#define IS_SVCID_UDP(_g) \
             ( ((((_g)->Data1) & 0xFFFF0000) == 0x000A0000) && \
               (((_g)->Data2) == 0) &&                       \
               (((_g)->Data3) == 0) &&                       \
               (((_g)->Data4[0]) == 0xC0) &&                 \
               (((_g)->Data4[1]) == 0) &&                    \
               (((_g)->Data4[2]) == 0) &&                    \
               (((_g)->Data4[3]) == 0) &&                    \
               (((_g)->Data4[4]) == 0) &&                    \
               (((_g)->Data4[5]) == 0) &&                    \
               (((_g)->Data4[6]) == 0) &&                    \
               (((_g)->Data4[7]) == 0x46) )

#define PORT_FROM_SVCID_UDP(_g) \
               ((WORD)(_g->Data1 & 0xFFFF))

#define SET_UDP_SVCID(_g,_Port) {                            \
               (_g)->Data1 = (0x000A << 16 ) | (_Port);      \
               (_g)->Data2 = 0;                              \
               (_g)->Data3 = 0;                              \
               (_g)->Data4[0] = 0xC0;                        \
               (_g)->Data4[1] = 0x0;                         \
               (_g)->Data4[2] = 0x0;                         \
               (_g)->Data4[3] = 0x0;                         \
               (_g)->Data4[4] = 0x0;                         \
               (_g)->Data4[5] = 0x0;                         \
               (_g)->Data4[6] = 0x0;                         \
               (_g)->Data4[7] = 0x46; }

//
// Macros for defining and testing Netware (SAP) services based on the 
// SAP ID.  
//

#define SVCID_NETWARE(_SapId) \
             { (0x000B << 16) | (_SapId), 0, 0, { 0xC0,0,0,0,0,0,0,0x46 } }
          
#define IS_SVCID_NETWARE(_g) \
             ( ((((_g)->Data1) & 0xFFFF0000) == 0x000B0000) && \
               (((_g)->Data2) == 0) &&                       \
               (((_g)->Data3) == 0) &&                       \
               (((_g)->Data4[0]) == 0xC0) &&                 \
               (((_g)->Data4[1]) == 0) &&                    \
               (((_g)->Data4[2]) == 0) &&                    \
               (((_g)->Data4[3]) == 0) &&                    \
               (((_g)->Data4[4]) == 0) &&                    \
               (((_g)->Data4[5]) == 0) &&                    \
               (((_g)->Data4[6]) == 0) &&                    \
               (((_g)->Data4[7]) == 0x46) )

#define SAPID_FROM_SVCID_NETWARE(_g) \
               ((WORD)(_g->Data1 & 0xFFFF))

#define SET_NETWARE_SVCID(_g,_SapId) {                       \
               (_g)->Data1 = (0x000B << 16 ) | (_SapId);     \
               (_g)->Data2 = 0;                              \
               (_g)->Data3 = 0;                              \
               (_g)->Data4[0] = 0xC0;                        \
               (_g)->Data4[1] = 0x0;                         \
               (_g)->Data4[2] = 0x0;                         \
               (_g)->Data4[3] = 0x0;                         \
               (_g)->Data4[4] = 0x0;                         \
               (_g)->Data4[5] = 0x0;                         \
               (_g)->Data4[6] = 0x0;                         \
               (_g)->Data4[7] = 0x46; }

//
// RFC 1060 services as defined by the IANA
// GUID block = 0009xxxx-0000-0000-C0000-000000000046
//

#define SVCID_ECHO_TCP                SVCID_TCP( 7 )
#define SVCID_DISCARD_TCP             SVCID_TCP( 9 )
#define SVCID_SYSTAT_TCP              SVCID_TCP( 11 )
#define SVCID_SYSTAT_TCP              SVCID_TCP( 11 )
#define SVCID_DAYTIME_TCP             SVCID_TCP( 13 )
#define SVCID_NETSTAT_TCP             SVCID_TCP( 15 )
#define SVCID_QOTD_TCP                SVCID_TCP( 17 )
#define SVCID_CHARGEN_TCP             SVCID_TCP( 19 )
#define SVCID_FTP_DATA_TCP            SVCID_TCP( 20 )
#define SVCID_FTP_TCP                 SVCID_TCP( 21 )
#define SVCID_TELNET_TCP              SVCID_TCP( 23 )
#define SVCID_SMTP_TCP                SVCID_TCP( 25 )
#define SVCID_TIME_TCP                SVCID_TCP( 37 )
#define SVCID_NAME_TCP                SVCID_TCP( 42 )
#define SVCID_WHOIS_TCP               SVCID_TCP( 43 )
#define SVCID_DOMAIN_TCP              SVCID_TCP( 53 )
#define SVCID_NAMESERVER_TCP          SVCID_TCP( 53 )
#define SVCID_MTP_TCP                 SVCID_TCP( 57 )
#define SVCID_RJE_TCP                 SVCID_TCP( 77 )
#define SVCID_FINGER_TCP              SVCID_TCP( 79 )
#define SVCID_LINK_TCP                SVCID_TCP( 87 )
#define SVCID_SUPDUP_TCP              SVCID_TCP( 95 )
#define SVCID_HOSTNAMES_TCP           SVCID_TCP( 101 )
#define SVCID_ISO_TSAP_TCP            SVCID_TCP( 102 )
#define SVCID_DICTIONARY_TCP          SVCID_TCP( 103 )
#define SVCID_X400_TCP                SVCID_TCP( 103 )
#define SVCID_X400_SND_TCP            SVCID_TCP( 104 )
#define SVCID_CSNET_NS_TCP            SVCID_TCP( 105 )
#define SVCID_POP_TCP                 SVCID_TCP( 109 )
#define SVCID_POP2_TCP                SVCID_TCP( 109 )
#define SVCID_POP3_TCP                SVCID_TCP( 110 )
#define SVCID_PORTMAP_TCP             SVCID_TCP( 111 )
#define SVCID_SUNRPC_TCP              SVCID_TCP( 111 )
#define SVCID_AUTH_TCP                SVCID_TCP( 113 )
#define SVCID_SFTP_TCP                SVCID_TCP( 115 )
#define SVCID_PATH_TCP                SVCID_TCP( 117 )
#define SVCID_UUCP_PATH_TCP           SVCID_TCP( 117 )
#define SVCID_NNTP_TCP                SVCID_TCP( 119 )
#define SVCID_NBSESSION_TCP           SVCID_TCP( 139 )
#define SVCID_NEWS_TCP                SVCID_TCP( 144 )
#define SVCID_TCPREPO_TCP             SVCID_TCP( 158 )
#define SVCID_PRINT_SRV_TCP           SVCID_TCP( 170 )
#define SVCID_VMNET_TCP               SVCID_TCP( 175 )
#define SVCID_VMNET0_TCP              SVCID_TCP( 400 )
#define SVCID_EXEC_TCP                SVCID_TCP( 512 )
#define SVCID_LOGIN_TCP               SVCID_TCP( 513 )
#define SVCID_SHELL_TCP               SVCID_TCP( 514 )
#define SVCID_PRINTER_TCP             SVCID_TCP( 515 )
#define SVCID_EFS_TCP                 SVCID_TCP( 520 )
#define SVCID_TEMPO_TCP               SVCID_TCP( 526 )
#define SVCID_COURIER_TCP             SVCID_TCP( 530 )
#define SVCID_CONFERENCE_TCP          SVCID_TCP( 531 )
#define SVCID_NETNEWS_TCP             SVCID_TCP( 532 )
#define SVCID_UUCP_TCP                SVCID_TCP( 540 )
#define SVCID_KLOGIN_TCP              SVCID_TCP( 543 )
#define SVCID_KSHELL_TCP              SVCID_TCP( 544 )
#define SVCID_REMOTEFS_TCP            SVCID_TCP( 556 )
#define SVCID_GARCON_TCP              SVCID_TCP( 600 )
#define SVCID_MAITRD_TCP              SVCID_TCP( 601 )
#define SVCID_BUSBOY_TCP              SVCID_TCP( 602 )
#define SVCID_KERBEROS_TCP            SVCID_TCP( 750 )
#define SVCID_KERBEROS_MASTER_TCP     SVCID_TCP( 751 )
#define SVCID_KRB_PROP_TCP            SVCID_TCP( 754 )
#define SVCID_ERLOGIN_TCP             SVCID_TCP( 888 )
#define SVCID_KPOP_TCP                SVCID_TCP( 1109 )
#define SVCID_INGRESLOCK_TCP          SVCID_TCP( 1524 )
#define SVCID_KNETD_TCP               SVCID_TCP( 2053 )
#define SVCID_EKLOGIN_TCP             SVCID_TCP( 2105 )
#define SVCID_RMT_TCP                 SVCID_TCP( 5555 )
#define SVCID_MTB_TCP                 SVCID_TCP( 5556 )
#define SVCID_MAN_TCP                 SVCID_TCP( 9535 )
#define SVCID_W_TCP                   SVCID_TCP( 9536 )
#define SVCID_MANTST_TCP              SVCID_TCP( 9537 )
#define SVCID_BNEWS_TCP               SVCID_TCP( 10000 )
#define SVCID_QUEUE_TCP               SVCID_TCP( 10001 )
#define SVCID_POKER_TCP               SVCID_TCP( 10002 )
#define SVCID_GATEWAY_TCP             SVCID_TCP( 10003 )
#define SVCID_REMP_TCP                SVCID_TCP( 10004 )
#define SVCID_QMASTER_TCP             SVCID_TCP( 10012 )

#define SVCID_ECHO_UDP                SVCID_UDP( 7 )
#define SVCID_DISCARD_UDP             SVCID_UDP( 9 )
#define SVCID_DAYTIME_UDP             SVCID_UDP( 13 )
#define SVCID_QOTD_UDP                SVCID_UDP( 17 )
#define SVCID_CHARGEN_UDP             SVCID_UDP( 19 )
#define SVCID_TIME_UDP                SVCID_UDP( 37 )
#define SVCID_RLP_UDP                 SVCID_UDP( 39 )
#define SVCID_NAME_UDP                SVCID_UDP( 42 )
#define SVCID_DOMAIN_UDP              SVCID_UDP( 53 )
#define SVCID_NAMESERVER_UDP          SVCID_UDP( 53 )
#define SVCID_BOOTP_UDP               SVCID_UDP( 67 )
#define SVCID_TFTP_UDP                SVCID_UDP( 69 )
#define SVCID_PORTMAP_UDP             SVCID_UDP( 111 )
#define SVCID_SUNRPC_UDP              SVCID_UDP( 111 )
#define SVCID_NTP_UDP                 SVCID_UDP( 123 )
#define SVCID_NBNAME_UDP              SVCID_UDP( 137 )
#define SVCID_NBDATAGRAM_UDP          SVCID_UDP( 138 )
#define SVCID_SGMP_UDP                SVCID_UDP( 153 )
#define SVCID_SNMP_UDP                SVCID_UDP( 161 )
#define SVCID_SNMP_TRAP_UDP           SVCID_UDP( 162 )
#define SVCID_LOAD_UDP                SVCID_UDP( 315 )
#define SVCID_SYTEK_UDP               SVCID_UDP( 500 )
#define SVCID_BIFF_UDP                SVCID_UDP( 512 )
#define SVCID_WHO_UDP                 SVCID_UDP( 513 )
#define SVCID_SYSLOG_UDP              SVCID_UDP( 514 )
#define SVCID_TALK_UDP                SVCID_UDP( 517 )
#define SVCID_NTALK_UDP               SVCID_UDP( 518 )
#define SVCID_ROUTE_UDP               SVCID_UDP( 520 )
#define SVCID_TIMED_UDP               SVCID_UDP( 525 )
#define SVCID_RVD_CONTROL_UDP         SVCID_UDP( 531 )
#define SVCID_NETWALL_UDP             SVCID_UDP( 533 )
#define SVCID_NEW_RWHO_UDP            SVCID_UDP( 550 )
#define SVCID_RMONITOR_UDP            SVCID_UDP( 560 )
#define SVCID_MONITOR_UDP             SVCID_UDP( 561 )
#define SVCID_ACCTMASTER_UDP          SVCID_UDP( 700 )
#define SVCID_ACCTSLAVE_UDP           SVCID_UDP( 701 )
#define SVCID_ACCT_UDP                SVCID_UDP( 702 )
#define SVCID_ACCTLOGIN_UDP           SVCID_UDP( 703 )
#define SVCID_ACCTPRINTER_UDP         SVCID_UDP( 704 )
#define SVCID_ELCSD_UDP               SVCID_UDP( 704 )
#define SVCID_ACCTINFO_UDP            SVCID_UDP( 705 )
#define SVCID_ACCTSLAVE2_UDP          SVCID_UDP( 706 )
#define SVCID_ACCTDISK_UDP            SVCID_UDP( 707 )
#define SVCID_KERBEROS_UDP            SVCID_UDP( 750 )
#define SVCID_KERBEROS_MASTER_UDP     SVCID_UDP( 751 )
#define SVCID_PASSWD_SERVER_UDP       SVCID_UDP( 752 )
#define SVCID_USERREG_SERVER_UDP      SVCID_UDP( 753 )
#define SVCID_PHONE_UDP               SVCID_UDP( 1167 )
#define SVCID_MAZE_UDP                SVCID_UDP( 1666 )
#define SVCID_NFS_UDP                 SVCID_UDP( 2049 )
#define SVCID_RSCS0_UDP               SVCID_UDP( 10000 )
#define SVCID_RSCS1_UDP               SVCID_UDP( 10001 )
#define SVCID_RSCS2_UDP               SVCID_UDP( 10002 )
#define SVCID_RSCS3_UDP               SVCID_UDP( 10003 )
#define SVCID_RSCS4_UDP               SVCID_UDP( 10004 )
#define SVCID_RSCS5_UDP               SVCID_UDP( 10005 )
#define SVCID_RSCS6_UDP               SVCID_UDP( 10006 )
#define SVCID_RSCS7_UDP               SVCID_UDP( 10007 )
#define SVCID_RSCS8_UDP               SVCID_UDP( 10008 )
#define SVCID_RSCS9_UDP               SVCID_UDP( 10009 )
#define SVCID_RSCSA_UDP               SVCID_UDP( 10010 )
#define SVCID_RSCSB_UDP               SVCID_UDP( 10011 )
#define SVCID_QMASTER_UDP             SVCID_UDP( 10012 )

//
// NetWare services
// GUID block = 000axxxx-0000-0000-C0000-000000000046
//

#define SVCID_PRINT_QUEUE                 SVCID_NETWARE( 0x3 )
#define SVCID_FILE_SERVER                 SVCID_NETWARE( 0x4 )
#define SVCID_JOB_SERVER                  SVCID_NETWARE( 0x5 )
#define SVCID_GATEWAY                     SVCID_NETWARE( 0x6 )
#define SVCID_PRINT_SERVER                SVCID_NETWARE( 0x7 )
#define SVCID_ARCHIVE_QUEUE               SVCID_NETWARE( 0x8 )
#define SVCID_ARCHIVE_SERVER              SVCID_NETWARE( 0x9 )
#define SVCID_JOB_QUEUE                   SVCID_NETWARE( 0xA )
#define SVCID_ADMINISTRATION              SVCID_NETWARE( 0xB )
#define SVCID_NAS_SNA_GATEWAY             SVCID_NETWARE( 0x21 )
#define SVCID_REMOTE_BRIDGE_SERVER        SVCID_NETWARE( 0x24 )
#define SVCID_TIME_SYNCHRONIZATION_SERVER SVCID_NETWARE( 0x2D )
#define SVCID_ARCHIVE_SERVER_DYNAMIC_SAP  SVCID_NETWARE( 0x2E )
#define SVCID_ADVERTISING_PRINT_SERVER    SVCID_NETWARE( 0x47 )
#define SVCID_BTRIEVE_VAP                 SVCID_NETWARE( 0x4B )
#define SVCID_DIRECTORY_SERVER            SVCID_NETWARE( 0x278 )
#define SVCID_NETWARE_386                 SVCID_NETWARE( 0x107 )
#define SVCID_HP_PRINT_SERVER             SVCID_NETWARE( 0x30C )
#define SVCID_SNA_SERVER                  SVCID_NETWARE( 0x444 )
#define SVCID_SAA_SERVER                  SVCID_NETWARE( 0x130 )

#endif // _SVCGUID_
