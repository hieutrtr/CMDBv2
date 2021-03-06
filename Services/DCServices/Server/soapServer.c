/* soapServer.c
   Generated by gSOAP 2.8.16 from rcx.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) soapServer.c ver 2.8.16 2014-02-21 09:10:56 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:newServer"))
		return soap_serve_ns2__newServer(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:updateServer"))
		return soap_serve_ns2__updateServer(soap);
	if (!soap_match_tag(soap, soap->tag, "ns2:removeServer"))
		return soap_serve_ns2__removeServer(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__newServer(struct soap *soap)
{	struct ns2__newServer soap_tmp_ns2__newServer;
	struct ns2__newServerResponse soap_tmp_ns2__newServerResponse;
	char * soap_tmp_string;
	soap_default_ns2__newServerResponse(soap, &soap_tmp_ns2__newServerResponse);
	soap_tmp_string = NULL;
	soap_tmp_ns2__newServerResponse.return_ = &soap_tmp_string;
	soap_default_ns2__newServer(soap, &soap_tmp_ns2__newServer);
	if (!soap_get_ns2__newServer(soap, &soap_tmp_ns2__newServer, "ns2:newServer", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__newServer(soap, soap_tmp_ns2__newServer.infoServer, soap_tmp_ns2__newServerResponse.return_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__newServerResponse(soap, &soap_tmp_ns2__newServerResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__newServerResponse(soap, &soap_tmp_ns2__newServerResponse, "ns2:newServerResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__newServerResponse(soap, &soap_tmp_ns2__newServerResponse, "ns2:newServerResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__updateServer(struct soap *soap)
{	struct ns2__updateServer soap_tmp_ns2__updateServer;
	struct ns2__updateServerResponse soap_tmp_ns2__updateServerResponse;
	char * soap_tmp_string;
	soap_default_ns2__updateServerResponse(soap, &soap_tmp_ns2__updateServerResponse);
	soap_tmp_string = NULL;
	soap_tmp_ns2__updateServerResponse.return_ = &soap_tmp_string;
	soap_default_ns2__updateServer(soap, &soap_tmp_ns2__updateServer);
	if (!soap_get_ns2__updateServer(soap, &soap_tmp_ns2__updateServer, "ns2:updateServer", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__updateServer(soap, soap_tmp_ns2__updateServer.infoServer, soap_tmp_ns2__updateServerResponse.return_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__updateServerResponse(soap, &soap_tmp_ns2__updateServerResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__updateServerResponse(soap, &soap_tmp_ns2__updateServerResponse, "ns2:updateServerResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__updateServerResponse(soap, &soap_tmp_ns2__updateServerResponse, "ns2:updateServerResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns2__removeServer(struct soap *soap)
{	struct ns2__removeServer soap_tmp_ns2__removeServer;
	struct ns2__removeServerResponse soap_tmp_ns2__removeServerResponse;
	char * soap_tmp_string;
	soap_default_ns2__removeServerResponse(soap, &soap_tmp_ns2__removeServerResponse);
	soap_tmp_string = NULL;
	soap_tmp_ns2__removeServerResponse.return_ = &soap_tmp_string;
	soap_default_ns2__removeServer(soap, &soap_tmp_ns2__removeServer);
	if (!soap_get_ns2__removeServer(soap, &soap_tmp_ns2__removeServer, "ns2:removeServer", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = ns2__removeServer(soap, soap_tmp_ns2__removeServer.serialNumber, soap_tmp_ns2__removeServerResponse.return_);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "http://schemas.xmlsoap.org/soap/encoding/";
	soap_serializeheader(soap);
	soap_serialize_ns2__removeServerResponse(soap, &soap_tmp_ns2__removeServerResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns2__removeServerResponse(soap, &soap_tmp_ns2__removeServerResponse, "ns2:removeServerResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns2__removeServerResponse(soap, &soap_tmp_ns2__removeServerResponse, "ns2:removeServerResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapServer.c */
