#pragma once

// For compilers that support precompilation, includes <wx/wx.h>
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <wx/event.h>
#include <wx/socket.h>
#include <wx/string.h>


class stClient : public wxEvtHandler
{
    public:
        stClient(unsigned int nServerPort, unsigned int nWritePort);
        ~stClient();
        bool StartServer();
        bool SendMessageToSourceTrail(const wxString& sMessage);
        void SendLocation();
    private:
        void OnSocketEvent(wxSocketEvent& event);
        void OnServerSocketEvent(wxSocketEvent& event);
        void HandleMessages(const wxString& sBuffer);
        void DecodeMessage(const wxString& sMessage);

        void MoveCursor(const wxString& sFile, unsigned long nLine, unsigned long nCol);

        void SendPing();


        wxSocketServer* m_pServer;

        bool m_bConnected;
        wxString m_sMessageBuffer;
        unsigned int m_nServerPort;
        unsigned int m_nWritePort;

        static const wxString MSG_END;
        static const wxString MSG_PING;
        static const wxString MSG_CURSOR;
        static const wxString MSG_CREATE_CDB;
};
