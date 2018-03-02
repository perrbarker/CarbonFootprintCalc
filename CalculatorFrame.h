/****************************************************************
File: CalculatorFrame.cpp
Description: declares the functions and items used in calculator frame
Author: Kyle MacGavin
Class: CSCI 120
Date:12/3/15

I hereby certify that this program is entirely my own work.
*****************************************************************/

#ifndef DRAWINGFRAME_H
#define DRAWINGFRAME_H

#include "wx/wx.h"
#include "wx/clrpicker.h"
#include "quiz2.h"
#include "AvgBST.h"

// IDs for GUI components
const int WINDOW_WIDTH = 1250; // window width
const int WINDOW_HEIGHT = 300; // window height
const wxString BACKGROUND_COLOR = "#ffffff"; // window background color

//global event IDs
const int ID_CLEAR_BTN = 0;
const int ID_SUBMIT_BTN = 1;
const int ID_CALC_BTN = 2;
const int ID_QUIZ_BTN = 3;
const int ID_NEXT_BTN = 4;
const int ID_END_BTN = 5;
const int ID_STAT_BTN = 6;
const int ID_HOME_BTN = 7;


/**
A frame that shows the drawing program interfaces.
*/
class CalculatorFrame : public wxFrame
{
public:
	//frame default constructor
	CalculatorFrame();
	
	/**********Buttons**********/
	//calculator button funciton
	void OnCalcButton(wxCommandEvent& event);
	//quiz button funciton
	void OnQuizButton(wxCommandEvent& event);
	//stat button funciton
	void OnStatButton(wxCommandEvent& event);
	//home button funciton
	void OnHomeButton(wxCommandEvent& event);
	//end button funciton
	void OnEndButton(wxCommandEvent& event);
	//clear button funciton
	void OnClearButton(wxCommandEvent& event);
	//submit button funciton
	void OnSubmitButton(wxCommandEvent& event);
	//next button funciton
	void OnNextButton(wxCommandEvent& event);
	
	//funciton to switch pages
	void Switch_Page(int pageNum);

private:

	//Quiz object delcaration
	Quiz quizObj;

	//BINARY SEARCH TREE
	AvgBST UserAvgs; 

	//Pageswitch integer
	int pageSwitch = 2;

	//answer index location
	int answerIndex = 0;

	//question index
	int questionIndex = 1;
	


	//Button declarations
	wxButton* calcButton;
	wxButton* quizButton;
	wxButton* submitButton;
	wxButton* clearButton;
	wxButton* nextButton;
	wxButton* endButton;
	wxButton* statButton;
	wxButton* homeButton;
	wxButton* homeQuizButton;
	wxButton* homeStatButton;


	// layout sizers
	wxBoxSizer *m_sizer = new wxBoxSizer(wxVERTICAL);



	//Frame Panels
	wxPanel *Mainpanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxPanel *Calculatorpanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxPanel *Quizpanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxPanel *Statpanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);



	/******************Calculator items*********************/
	//Calculator Checkboxes
	//Recycle Metal Checkbox
	wxCheckBox *MetalCHK = new wxCheckBox(Calculatorpanel, wxID_ANY, "Metal", wxPoint(850, 120));
	//Recycle Plastic Checkbox
	wxCheckBox *PlasticCHK = new wxCheckBox(Calculatorpanel, wxID_ANY, "Plastic", wxPoint(950, 120));
	//Recycle Paper Checkbox
	wxCheckBox *PaperCHK = new wxCheckBox(Calculatorpanel, wxID_ANY, "Paper", wxPoint(1050, 120));
	//Recycle Magazines Checkbox
	wxCheckBox *MagazinesCHK = new wxCheckBox(Calculatorpanel, wxID_ANY, "Magazines", wxPoint(900, 160));
	//Recycle Glass Checkbox
	wxCheckBox *GlassCHK = new wxCheckBox(Calculatorpanel, wxID_ANY, "Glass", wxPoint(1020, 160));

	//Calculator Textboxes
	//MPG Textbox
	wxTextCtrl *MPGtext = new wxTextCtrl(Calculatorpanel, wxID_ANY, wxString("0"), wxPoint(200, 120));
	//Traveled Textbox
	wxTextCtrl *Traveledtext = new wxTextCtrl(Calculatorpanel, wxID_ANY, wxString("0"), wxPoint(200, 150));
	//Carpool Textbox
	wxTextCtrl *Pooltext = new wxTextCtrl(Calculatorpanel, wxID_ANY, wxString("1"), wxPoint(200, 180));
	//kWh textbox
	wxTextCtrl *KWHtext = new wxTextCtrl(Calculatorpanel, wxID_ANY, wxString("0"), wxPoint(640, 70));
	//People per house textbox
	wxTextCtrl *Peopletext = new wxTextCtrl(Calculatorpanel, wxID_ANY, wxString("0"), wxPoint(640, 120));
	//Propane use textbox
	wxTextCtrl *Propanetext = new wxTextCtrl(Calculatorpanel, wxID_ANY, wxString("0"), wxPoint(640, 180));



	/*****************Quiz Items***********************/
	//Labels
	wxStaticText *Question1 = new wxStaticText(Quizpanel, wxID_ANY, "Question 1", wxPoint(600, 8));
	wxStaticText *Question2 = new wxStaticText(Quizpanel, wxID_ANY, "Question 2", wxPoint(600, 8));
	wxStaticText *Question3 = new wxStaticText(Quizpanel, wxID_ANY, "Question 3", wxPoint(600, 8));
	wxStaticText *Question4 = new wxStaticText(Quizpanel, wxID_ANY, "Question 4", wxPoint(600, 8));
	wxStaticText *Question5 = new wxStaticText(Quizpanel, wxID_ANY, "Question 5", wxPoint(600, 8));
	wxStaticText *Question6 = new wxStaticText(Quizpanel, wxID_ANY, "Question 6", wxPoint(600, 8));
	wxStaticText *Question7 = new wxStaticText(Quizpanel, wxID_ANY, "Question 7", wxPoint(600, 8));
	wxStaticText *Question8 = new wxStaticText(Quizpanel, wxID_ANY, "Question 8", wxPoint(600, 8));
	wxStaticText *Question9 = new wxStaticText(Quizpanel, wxID_ANY, "Question 9", wxPoint(600, 8));
	wxStaticText *Question10 = new wxStaticText(Quizpanel, wxID_ANY, "Question 10", wxPoint(600, 8));
	wxStaticText *Question11 = new wxStaticText(Quizpanel, wxID_ANY, "Question 11", wxPoint(600, 8));
	wxStaticText *Question12 = new wxStaticText(Quizpanel, wxID_ANY, "Question 12", wxPoint(600, 8));
	wxStaticText *Question13 = new wxStaticText(Quizpanel, wxID_ANY, "Question 13", wxPoint(600, 8));
	wxStaticText *Question14 = new wxStaticText(Quizpanel, wxID_ANY, "Question 14", wxPoint(600, 8));
	wxStaticText *Question15 = new wxStaticText(Quizpanel, wxID_ANY, "Question 15", wxPoint(600, 8));

	

	//Changing labels and answers
	wxStaticText *QuizQuestion = new wxStaticText(Quizpanel, wxID_ANY, "", wxPoint(500, 50));
	wxStaticText *AnswerA = new wxStaticText(Quizpanel, wxID_ANY, "", wxPoint(325, 100));
	wxStaticText *AnswerB = new wxStaticText(Quizpanel, wxID_ANY, "", wxPoint(805, 100));
	wxStaticText *AnswerC = new wxStaticText(Quizpanel, wxID_ANY, "", wxPoint(325, 200));
	wxStaticText *AnswerD = new wxStaticText(Quizpanel, wxID_ANY, "", wxPoint(805, 200));

	//radio buttons
	wxRadioButton *radioA = new wxRadioButton(Quizpanel, wxID_ANY, wxString(""), wxPoint(300, 100), wxDefaultSize, 0, wxDefaultValidator, wxString("A"));
	wxRadioButton *radioB = new wxRadioButton(Quizpanel, wxID_ANY, wxString(""), wxPoint(780, 100), wxDefaultSize, 0, wxDefaultValidator, wxString("B"));
	wxRadioButton *radioC = new wxRadioButton(Quizpanel, wxID_ANY, wxString(""), wxPoint(300, 200), wxDefaultSize, 0, wxDefaultValidator, wxString("C"));
	wxRadioButton *radioD = new wxRadioButton(Quizpanel, wxID_ANY, wxString(""), wxPoint(780, 200), wxDefaultSize, 0, wxDefaultValidator, wxString("D"));
	//Quiz answers storage
	std::vector <char> quizAnswer;
		
	

	/*************Stats declarations*****************/
	//static text
	wxStaticText *StatTexts = new wxStaticText(Statpanel, wxID_ANY, "", wxPoint(450, 35));
	wxStaticText *StatHead = new wxStaticText(Statpanel, wxID_ANY, "Carbon Pounds Per Year:", wxPoint(550, 8));




	DECLARE_EVENT_TABLE()
};




#endif