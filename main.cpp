/****************************************************************
File:
Description:

Author:
Class:
Date:

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include <wx/wx.h>
#include "CalculatorFrame.h"
#include "Person.h"
#include "AvgBST.h"

/**
A drawing application for basic geometrical shapes.
*/

class DrawingApp : public wxApp
{
public:
	/**
	Constructs and shows the frame.
	@return true
	*/
	virtual bool OnInit();
private:
	CalculatorFrame* frame;
};

DECLARE_APP(DrawingApp)

IMPLEMENT_APP(DrawingApp)





BEGIN_EVENT_TABLE(CalculatorFrame, wxFrame)
EVT_BUTTON(ID_STAT_BTN, CalculatorFrame::OnStatButton)
EVT_BUTTON(ID_CLEAR_BTN, CalculatorFrame::OnClearButton)
EVT_BUTTON(ID_SUBMIT_BTN, CalculatorFrame::OnSubmitButton)
EVT_BUTTON(ID_CALC_BTN, CalculatorFrame::OnCalcButton)
EVT_BUTTON(ID_NEXT_BTN, CalculatorFrame::OnNextButton)
EVT_BUTTON(ID_END_BTN, CalculatorFrame::OnEndButton)
EVT_BUTTON(ID_QUIZ_BTN, CalculatorFrame::OnQuizButton)
EVT_BUTTON(ID_HOME_BTN, CalculatorFrame::OnHomeButton)
END_EVENT_TABLE()

/**
Constructs and shows the frame.
@return true
*/
bool DrawingApp::OnInit()
{
	frame = new CalculatorFrame();
	frame->Show(true);
	return true;
}
