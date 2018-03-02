/****************************************************************
File: CalculatorFrame.cpp
Description: Creates the frame, panels, and uses the calculator and quiz functions to create the program
Author: Kyle MacGavin
Class: CSCI 120
Date:12/3/15

I hereby certify that this program is entirely my own work.
*****************************************************************/

#include "CalculatorFrame.h"
#include "Person.h"
#include "AvgBST.h"
#include "quiz2.h"

#include <fstream>




/*Creates the frame, layout, sets location of buttons and other items*/
CalculatorFrame::CalculatorFrame()
	: wxFrame(NULL, -1, "Carbon Footprint Fun", wxPoint(-1, -1), wxSize(WINDOW_WIDTH, WINDOW_HEIGHT))
{
	this->SetSizer(m_sizer);

	/******************Panel 0 Mainpanel***************************/
	//Main header
	wxStaticText *Mainlabel = new wxStaticText(Mainpanel, wxID_ANY, "Please select what feature you wish to use:", wxPoint(495, 70));

	//Home page buttons
	calcButton = new wxButton(Mainpanel, ID_CALC_BTN, "Calculator", wxPoint(500, 130));
	quizButton = new wxButton(Mainpanel, ID_QUIZ_BTN, "Quiz", wxPoint(630, 130));
	statButton = new wxButton(Mainpanel, ID_STAT_BTN, "Calculator Statistics", wxPoint(550, 230));
	//sizer for the panels
	m_sizer->Add(Mainpanel, 1, wxEXPAND);


	/***********************************Panel 1 Calculator****************************************************/
	//Points and sizer for the boxes
	wxPoint boxPoint1(0, 0);
	wxPoint boxPoint2(400, 0);
	wxPoint boxPoint3(800, 0);
	wxSize boxSize(380, 230);

	//Box declarations for organization
	wxStaticBox *box = new wxStaticBox(Calculatorpanel, wxID_ANY, "Transportation", boxPoint1, boxSize);
	wxStaticBox *box2 = new wxStaticBox(Calculatorpanel, wxID_ANY, "Household", boxPoint2, boxSize);
	wxStaticBox *box3 = new wxStaticBox(Calculatorpanel, wxID_ANY, "Waste", boxPoint3, boxSize);


	/****************Validator for calculator textboxes******************/
	wxTextValidator validator(wxFILTER_INCLUDE_CHAR_LIST);
	wxArrayString list;
	wxString valid_chars(wxT(" 0123456789"));
	size_t len = valid_chars.Length();
	for (size_t i = 0; i<len; i++)
		list.Add(wxString(valid_chars.GetChar(i)));
	validator.SetIncludes(list);
	MPGtext->SetValidator(validator);
	Traveledtext->SetValidator(validator);
	Pooltext->SetValidator(validator);
	KWHtext->SetValidator(validator);
	Peopletext->SetValidator(validator);
	Propanetext->SetValidator(validator);




	/********************* Transportation Section************************************/
	//Transportation Title Label
	wxStaticText *privateTRANSlabel = new wxStaticText(Calculatorpanel, wxID_ANY, "Private Transportation", wxPoint(150, 70), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);

	//MPG label
	wxStaticText *MPGlabel = new wxStaticText(Calculatorpanel, wxID_ANY, "Miles Per Gallon", wxPoint(100, 123));

	//setup for Traveled box and label
	wxStaticText *Traveledlabel = new wxStaticText(Calculatorpanel, wxID_ANY, "Miles Traveled", wxPoint(100, 153));

	//setup for carpool box and label
	wxStaticText *Poollabel = new wxStaticText(Calculatorpanel, wxID_ANY, "Size of Carpool", wxPoint(100, 183));


	/********Household Section*************/

	//electricity label

	wxStaticText *KWHlabel = new wxStaticText(Calculatorpanel, wxID_ANY, "Electricity bill per month", wxPoint(440, 73));

	//people per house label

	wxStaticText *Peoplelabel = new wxStaticText(Calculatorpanel, wxID_ANY, "How many people in your house", wxPoint(440, 123));

	//propane usage  label

	wxStaticText *Propanelabel = new wxStaticText(Calculatorpanel, wxID_ANY, "Propane gallons used monthly ", wxPoint(440, 183));




	/***********Waste Section*****************/

	//Recycle Label
	wxStaticText *Recyclelabel = new wxStaticText(Calculatorpanel, wxID_ANY, "Select All Items That You Recycle:", wxPoint(900, 70));

	// buttons
	submitButton = new wxButton(Calculatorpanel, ID_SUBMIT_BTN, "Submit", wxPoint(400, 233));
	clearButton = new wxButton(Calculatorpanel, ID_CLEAR_BTN, "Clear", wxPoint(550, 233));
	homeButton = new wxButton(Calculatorpanel, ID_HOME_BTN, "Return", wxPoint(695, 233));

	//hides the panel
	Calculatorpanel->Hide();

	/***********************************Panel 2 Quizes****************************************************/
	//Buttons
	endButton = new wxButton(Quizpanel, ID_END_BTN, "End", wxPoint(500, 233));
	nextButton = new wxButton(Quizpanel, ID_NEXT_BTN, "Next", wxPoint(500, 233));
	homeQuizButton = new wxButton(Quizpanel, ID_HOME_BTN, "Return", wxPoint(650, 233));

	Quizpanel->Hide();

	/******************************Panel 3 Stats****************************************/
	//Stat home page button
	homeStatButton = new wxButton(Statpanel, ID_HOME_BTN, "Return", wxPoint(565, 230));
	Statpanel->Hide();


}
//Function to switch between panels and menus
void CalculatorFrame::Switch_Page(int pageNum){

	//Switch for the page number selected
	switch (pageNum){
	case 0:
		m_sizer->Detach(0);
		Quizpanel->Hide();
		Calculatorpanel->Hide();
		homeStatButton->Hide();
		StatTexts->Hide();
		StatHead->Hide();
		m_sizer->Prepend(Mainpanel, 1, wxEXPAND);
		Mainpanel->Show();
		break;

	case 1:
		m_sizer->Detach(0);
		Quizpanel->Hide();
		Mainpanel->Hide();
		Calculatorpanel->Update();
		m_sizer->Prepend(Calculatorpanel, 1, wxEXPAND);
		Calculatorpanel->Show();
		break;

	case 2:
		m_sizer->Detach(0);
		Calculatorpanel->Hide();
		Mainpanel->Hide();
		m_sizer->Prepend(Quizpanel, 1, wxEXPAND);
		endButton->Hide();
		nextButton->Show();
		Quizpanel->Show();
		Question1->Show();
		Question2->Hide();
		Question3->Hide();
		Question4->Hide();
		Question5->Hide();
		Question6->Hide();
		Question7->Hide();
		Question8->Hide();
		Question9->Hide();
		Question10->Hide();
		Question11->Hide();
		Question12->Hide();
		Question13->Hide();
		Question14->Hide();
		Question15->Hide();
		break;

	case 3:
		Question1->Hide();
		Question2->Show();
		Question3->Hide();

		break;

	case 4:
		Question2->Hide();
		Question3->Show();
		Question4->Hide();

		break;

	case 5:
		Question3->Hide();
		Question4->Show();
		Question5->Hide();
		break;

	case 6:
		Question4->Hide();
		Question5->Show();
		Question6->Hide();
		break;

	case 7:
		Question5->Hide();
		Question6->Show();
		Question7->Hide();

		break;
	case 8:
		Question6->Hide();
		Question7->Show();
		Question8->Hide();
		break;
	case 9:

		Question7->Hide();
		Question8->Show();
		Question9->Hide();
		break;

	case 10:
		Question8->Hide();
		Question9->Show();
		Question10->Hide();
		break;

	case 11:
		Question9->Hide();
		Question10->Show();
		Question11->Hide();
		break;

	case 12:
		Question10->Hide();
		Question11->Show();
		Question12->Hide();
		break;

	case 13:
		Question11->Hide();
		Question12->Show();
		Question13->Hide();
		break;

	case 14:
		Question12->Hide();
		Question13->Show();
		Question14->Hide();
		break;

	case 15:
		Question13->Hide();
		Question14->Show();
		Question15->Hide();
		nextButton->Show();
		endButton->Hide();
		break;

	case 16:
		nextButton->Hide();
		endButton->Show();
		Question14->Hide();
		Question15->Show();
		break;

	case 20:
		m_sizer->Detach(0);
		Calculatorpanel->Hide();
		Mainpanel->Hide();
		endButton->Hide();
		Quizpanel->Hide();
		Statpanel->Show();
		StatTexts->Show();
		m_sizer->Prepend(Statpanel, 1, wxEXPAND);
		Statpanel->Show();

	}
	m_sizer->Layout();

}

//Main page calculator button function
void CalculatorFrame::OnCalcButton(wxCommandEvent& event){
	Switch_Page(1);
}

//Main page stat Button function
void CalculatorFrame::OnStatButton(wxCommandEvent& event) {
	
	homeStatButton->Show();

	//open and streams the file to string
	std::string line;
	std::ifstream myfile("InProject.txt");
	if (myfile.is_open())
	{
		getline(myfile, line);
		myfile.close();
	}
	//Sets the label to the file string
	StatTexts->SetLabelText(line);
	StatTexts->Wrap(500);
	Switch_Page(20);

}




//submit for the calculator function
void CalculatorFrame::OnSubmitButton(wxCommandEvent& event) {

	//Stored values of the textboxes
	int MPG = atoi(MPGtext->GetValue().c_str()); //mpg textbox
	int Traveled = atoi(Traveledtext->GetValue().c_str()); //traveled textbox
	int Pool = atoi(Pooltext->GetValue().c_str()); //carpool textbox
	int KWH = atoi(KWHtext->GetValue().c_str()); //energy used textbox
	int People = atoi(Peopletext->GetValue().c_str()); //people per house textbox
	int Propane = atoi(Propanetext->GetValue().c_str()); //propane use textbox

	//Getters for the checkboxes RETURNS BOOLEAN VALUE
	MetalCHK->GetValue();
	PlasticCHK->GetValue();
	PaperCHK->GetValue();
	MagazinesCHK->GetValue();
	GlassCHK->GetValue();


	//dialog popup for entering name
	wxTextEntryDialog* dialog = new wxTextEntryDialog(this,
		"Please Enter Your Name:");

	
	//If ok is pressed all the information gets saved
	if (dialog->ShowModal() == wxID_OK){
		Person User;
		
		User.setUserName(dialog->GetValue().ToStdString());
		User.setHouseholdSize(People);
		User.setElectricUsage(KWH);
		User.setGasUsage(Propane);
		User.setCarPoolSize(Pool);
		User.setDailyMiles(Traveled);
		User.setCarMPG(MPG, Pool);
		User.recyGlass(GlassCHK->GetValue());
		User.recyMagazines(MagazinesCHK->GetValue());
		User.recyMetal(MetalCHK->GetValue());
		User.recyNewspaper(PaperCHK->GetValue());
		User.recyPlastic(PlasticCHK->GetValue());
		User.calcCarbonFootprint();

		UserAvgs.insert(User);

		UserAvgs.displayInOrder();
		Switch_Page(0);
	}

	//if any other button is pressed the dialog gets destroyed 
	dialog->Destroy();

	//Set calculator object values to default
	MPGtext->ChangeValue("0");
	Traveledtext->ChangeValue("0");
	Pooltext->ChangeValue("1");
	KWHtext->ChangeValue("0");
	Peopletext->ChangeValue("0");
	Propanetext->ChangeValue("0");
	MetalCHK->SetValue(false);
	PlasticCHK->SetValue(false);
	PaperCHK->SetValue(false);
	MagazinesCHK->SetValue(false);
	GlassCHK->SetValue(false);


}

//Clear button for the calculator app
void CalculatorFrame::OnClearButton(wxCommandEvent& event) {

	MPGtext->ChangeValue("0");
	Traveledtext->ChangeValue("0");
	Pooltext->ChangeValue("1");
	KWHtext->ChangeValue("0");
	Peopletext->ChangeValue("0");
	Propanetext->ChangeValue("0");
	MetalCHK->SetValue(false);
	PlasticCHK->SetValue(false);
	PaperCHK->SetValue(false);
	MagazinesCHK->SetValue(false);
	GlassCHK->SetValue(false);
	Switch_Page(1);
}

//Return button for calculator app
void CalculatorFrame::OnHomeButton(wxCommandEvent& event) {
	Switch_Page(0);
	pageSwitch = 2;

	MPGtext->ChangeValue("0");
	Traveledtext->ChangeValue("0");
	Pooltext->ChangeValue("1");
	KWHtext->ChangeValue("0");
	Peopletext->ChangeValue("0");
	Propanetext->ChangeValue("0");
	MetalCHK->SetValue(false);
	PlasticCHK->SetValue(false);
	PaperCHK->SetValue(false);
	MagazinesCHK->SetValue(false);
	GlassCHK->SetValue(false);
	questionIndex = 1;
	quizAnswer.clear();
	
}

//Main page quiz button
void CalculatorFrame::OnQuizButton(wxCommandEvent& event){
	
	radioA->SetValue(true);
	//sets the questions
	quizObj.setQuestions();
	//this function randomizes the quesitons
	quizObj.askQuestion();
	
	//sets the labels for the questions and answers
	QuizQuestion->SetLabelText(quizObj.printQuestion());
	QuizQuestion->Wrap(300);
	AnswerA->SetLabelText(quizObj.printFirstP());
	AnswerA->Wrap(300);
	AnswerB->SetLabelText(quizObj.printSecondP());
	AnswerB->Wrap(300);
	AnswerC->SetLabelText(quizObj.PrintThirdP());
	AnswerC->Wrap(300);
	AnswerD->SetLabelText(quizObj.printFourthP());
	AnswerD->Wrap(300);
	//switches the page
	Switch_Page(2);
}


//Next button for quiz app
void CalculatorFrame::OnNextButton(wxCommandEvent& event) {
	//references the ask question function in quiz2 cpp
	quizObj.askQuestion();
	//prints the question
	QuizQuestion->SetLabelText(quizObj.printQuestion());
	QuizQuestion->Wrap(300);
	//prints the answers
	AnswerA->SetLabelText(quizObj.printFirstP());
	AnswerA->Wrap(300);
	AnswerB->SetLabelText(quizObj.printSecondP());
	AnswerB->Wrap(300);
	AnswerC->SetLabelText(quizObj.PrintThirdP());
	AnswerC->Wrap(300);
	AnswerD->SetLabelText(quizObj.printFourthP());
	AnswerD->Wrap(300);
	
	//checks which radio button is pressed then stores it in vector
	if (radioA->GetValue()) quizAnswer.push_back('a');
	else if (radioB->GetValue()) quizAnswer.push_back('b');
	else if (radioC->GetValue())quizAnswer.push_back('c');
	else if (radioD->GetValue())quizAnswer.push_back('d');
	//resets the default radio button
	radioA->SetValue(true);

	pageSwitch = pageSwitch + 1;
	Switch_Page(pageSwitch);

}






//End button for quiz app
void CalculatorFrame::OnEndButton(wxCommandEvent& event) {
	//pops up dialog with score
	wxDialog* dialog = new wxDialog(this, wxID_ANY,
		"Your Score:");
	wxPanel *panel = new wxPanel(dialog, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);

	//trips the quiz2 cpp function for finding the score
	wxStaticText *Scorelabel = new wxStaticText(panel, wxID_ANY, quizObj.checkAnswers(quizAnswer), wxPoint(210, 85));
	wxStaticText *preScorelabel = new wxStaticText(panel, wxID_ANY, "Correct Answers:", wxPoint(120, 85));
	dialog->ShowModal();

	pageSwitch = 2;
	Switch_Page(0);
	dialog->Destroy();

}











