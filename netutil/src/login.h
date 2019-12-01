#ifndef _LOGIN_H__
#define _LOGIN_H__

namespace netutil{
    class CLogin{
        public:
        CLogin();
        virtual ~CLogin();

        private:
        std::string strUserID;
        std::string strUserPwd;
    };
}


#endif