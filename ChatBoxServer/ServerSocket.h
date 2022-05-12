#pragma once
#include <afxsock.h>
class ServerSocket :
    public CSocket
{
public:
    ServerSocket();
    virtual ~ServerSocket();
public:
    virtual void OnAccept(int nErrorCode);
};

