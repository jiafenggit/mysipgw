/* sipgwsipgwService.h
   Generated by gSOAP 2.8.70 for sipgwSvr.h

gSOAP XML Web services tools
Copyright (C) 2000-2018, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#ifndef sipgwsipgwService_H
#define sipgwsipgwService_H
#include "sipgwH.h"

    class SOAP_CMAC sipgwService {
      public:
        /// Context to manage service IO and data
        struct soap *soap;
        bool soap_own;  ///< flag indicating that this context is owned by this service when context is shared
        /// Variables globally declared in sipgwSvr.h, if any
        /// Construct a service with new managing context
        sipgwService();
        /// Copy constructor
        sipgwService(const sipgwService&);
        /// Construct service given a shared managing context
        sipgwService(struct soap*);
        /// Constructor taking input+output mode flags for the new managing context
        sipgwService(soap_mode iomode);
        /// Constructor taking input and output mode flags for the new managing context
        sipgwService(soap_mode imode, soap_mode omode);
        /// Destructor deletes non-shared managing context only (use destroy() to delete deserialized data)
        virtual ~sipgwService();
        /// Delete all deserialized data (with soap_destroy() and soap_end())
        virtual void destroy();
        /// Delete all deserialized data and reset to defaults
        virtual void reset();
        /// Initializer used by constructors
        virtual void sipgwService_init(soap_mode imode, soap_mode omode);
        /// Return a copy that has a new managing context with the same engine state
        virtual sipgwService *copy() SOAP_PURE_VIRTUAL_COPY;
        /// Copy assignment
        sipgwService& operator=(const sipgwService&);
        /// Close connection (normally automatic)
        virtual int soap_close_socket();
        /// Force close connection (can kill a thread blocked on IO)
        virtual int soap_force_close_socket();
        /// Return sender-related fault to sender
        virtual int soap_senderfault(const char *string, const char *detailXML);
        /// Return sender-related fault with SOAP 1.2 subcode to sender
        virtual int soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML);
        /// Return receiver-related fault to sender
        virtual int soap_receiverfault(const char *string, const char *detailXML);
        /// Return receiver-related fault with SOAP 1.2 subcode to sender
        virtual int soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML);
        /// Print fault
        virtual void soap_print_fault(FILE*);
    #ifndef WITH_LEAN
    #ifndef WITH_COMPAT
        /// Print fault to stream
        virtual void soap_stream_fault(std::ostream&);
    #endif
        /// Write fault to buffer
        virtual char *soap_sprint_fault(char *buf, size_t len);
    #endif
        /// Disables and removes SOAP Header from message by setting soap->header = NULL
        virtual void soap_noheader();
        /// Get SOAP Header structure (i.e. soap->header, which is NULL when absent)
        virtual ::SOAP_ENV__Header *soap_header();
    #ifndef WITH_NOIO
        /// Run simple single-thread (iterative, non-SSL) service on port until a connection error occurs (returns SOAP_OK or error code), use this->bind_flag = SO_REUSEADDR to rebind for immediate rerun
        virtual int run(int port);
    #if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
        /// Run simple single-thread SSL service on port until a connection error occurs (returns SOAP_OK or error code), use this->bind_flag = SO_REUSEADDR to rebind for immediate rerun
        virtual int ssl_run(int port);
    #endif
        /// Bind service to port (returns master socket or SOAP_INVALID_SOCKET)
        virtual SOAP_SOCKET bind(const char *host, int port, int backlog);
        /// Accept next request (returns socket or SOAP_INVALID_SOCKET)
        virtual SOAP_SOCKET accept();
    #if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
        /// When SSL is used, after accept() should perform and accept SSL handshake
        virtual int ssl_accept();
    #endif
    #endif
        /// After accept() serve this request (returns SOAP_OK or error code)
        virtual int serve();
        /// Used by serve() to dispatch a request (returns SOAP_OK or error code)
        virtual int dispatch();
        virtual int dispatch(struct soap *soap);
        ///
        /// Service operations are listed below (you should define these)
        /// Note: compile with -DWITH_PURE_VIRTUAL for pure virtual methods
        ///
        /// Web service operation 'login' (returns SOAP_OK or error code)
        virtual int login(char *user_id, char *password, int &result) SOAP_PURE_VIRTUAL;
        /// Web service operation 'logout' (returns SOAP_OK or error code)
        virtual int logout(char *user_id, char *password, int &result) SOAP_PURE_VIRTUAL;
        /// Web service operation 'keepalive' (returns SOAP_OK or error code)
        virtual int keepalive(char *user_id, char *password, int &result) SOAP_PURE_VIRTUAL;
        /// Web service operation 'get-directory-info' (returns SOAP_OK or error code)
        virtual int get_directory_info(char *target_dev_id, char *target_realm, char **directory_info_buf_out) SOAP_PURE_VIRTUAL;
        /// Web service operation 'ptz-control' (returns SOAP_OK or error code)
        virtual int ptz_control(char *target_dev_id, char *target_realm, int ptz, int ptz_speed, int &result) SOAP_PURE_VIRTUAL;
        /// Web service operation 'start-real-play' (returns SOAP_OK or error code)
        virtual int start_real_play(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, int &result) SOAP_PURE_VIRTUAL;
        /// Web service operation 'stop-real-play' (returns SOAP_OK or error code)
        virtual int stop_real_play(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, int &result) SOAP_PURE_VIRTUAL;
        /// Web service operation 'start-play-back' (returns SOAP_OK or error code)
        virtual int start_play_back(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, char *start_time, char *end_time, int &result) SOAP_PURE_VIRTUAL;
        /// Web service operation 'stop-play-back' (returns SOAP_OK or error code)
        virtual int stop_play_back(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, char *start_time, char *end_time, int &result) SOAP_PURE_VIRTUAL;
        /// Web service operation 'pause-play-back' (returns SOAP_OK or error code)
        virtual int pause_play_back(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, int &result) SOAP_PURE_VIRTUAL;
        /// Web service operation 'restart-play-back' (returns SOAP_OK or error code)
        virtual int restart_play_back(char *user_id, char *target_dev_id, char *target_realm, char *media_recv_ip, int media_recv_port, int &result) SOAP_PURE_VIRTUAL;
    };
#endif
