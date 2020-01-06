#include "wx/wxprec.h"
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

const wxString appName = "Pierwszy program";

class MyApp : public wxApp
{
    public:
        virtual bool OnInit();
};

class MyFrame : public wxFrame
{
    public:
        MyFrame(const wxString& title);
};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    MyFrame *frame  = new MyFrame(appName);
    frame->Show(true);

    return true;
}

MyFrame::MyFrame(const wxString& title)
: wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400))
{
    CenterOnScreen();
}
