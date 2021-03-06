#pragma once

#include "Elements.h"
#include "Sketch.h"

namespace CLRSketcher {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
  using namespace System::IO;

  enum class ElementType {LINE, RECTANGLE, CIRCLE, CURVE};
  enum class Mode {Normal, Move, Rotate};
	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
    Form1(void): elementType(ElementType::LINE), color(Color::Black)
      , drawing(false)
      , firstPoint(0), sketch(gcnew Sketch()), 
      highlightedElement(nullptr), mode(Mode::Normal)
    {
      FileStream^ fs = gcnew FileStream(L"TraceIt.txt", FileMode::Create);
      StreamWriter^ sw = gcnew StreamWriter(fs);
      sw->AutoFlush = true;
Console::SetOut( sw);
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
  private: System::Windows::Forms::MenuStrip^  menuStrip1;
  protected: 
  private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  newToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator;
  private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
  private: System::Windows::Forms::ToolStripMenuItem^  printToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  printPreviewToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
  private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  undoToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  redoToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
  private: System::Windows::Forms::ToolStripMenuItem^  cutToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
  private: System::Windows::Forms::ToolStripMenuItem^  selectAllToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  toolsToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  customizeToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  elementToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  lineToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  rectangleToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  circleToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  curveToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  contentsToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  indexToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  searchToolStripMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
  private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  colorToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  redToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  greenToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  blueToolStripMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  blackToolStripMenuItem;
  private: System::Windows::Forms::ToolStrip^  toolStrip1;
  private: System::Windows::Forms::ToolStripButton^  newToolStripButton;
  private: System::Windows::Forms::ToolStripButton^  openToolStripButton;
  private: System::Windows::Forms::ToolStripButton^  saveToolStripButton;
  private: System::Windows::Forms::ToolStripButton^  printToolStripButton;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
  private: System::Windows::Forms::ToolStripButton^  toolStripLineButton;
  private: System::Windows::Forms::ToolStripButton^  rectangleToolStripButton;
  private: System::Windows::Forms::ToolStripButton^  circleToolStripButton;
  private: System::Windows::Forms::ToolStripButton^  curveToolStripButton;
  private: System::Windows::Forms::ToolStripButton^  blackToolStripButton;
  private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator8;
  private: System::Windows::Forms::ToolStripButton^  redToolStripButton;
  private: System::Windows::Forms::ToolStripButton^  greenToolStripButton;
  private: System::Windows::Forms::ToolStripButton^  blueToolStripButton;
  private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
  private: System::Windows::Forms::ToolStripMenuItem^  moveContextMenuItem;

  private: System::Windows::Forms::ToolStripMenuItem^  sendToBackContextMenuItem;
  private: System::Windows::Forms::ToolStripSeparator^  contextSeparator;

  private: System::Windows::Forms::ToolStripMenuItem^  lineContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  rectangleContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  circleContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  curveContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  blackContextMenuItem;

  private: System::Windows::Forms::ToolStripMenuItem^  redContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  greenContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  blueContextMenuItem;
  private: System::Windows::Forms::ToolStripMenuItem^  deleteContextMenuItem;














  private: System::ComponentModel::IContainer^  components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
      this->components = (gcnew System::ComponentModel::Container());
      System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
      this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
      this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->newToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->printToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->printPreviewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->cutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->selectAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->customizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->elementToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->lineToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->rectangleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->circleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->curveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->colorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->blackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->redToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->greenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->blueToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->contentsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->indexToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
      this->newToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->openToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->saveToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->printToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->toolStripLineButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->rectangleToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->circleToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->curveToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->toolStripSeparator8 = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->blackToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->redToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->greenToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->blueToolStripButton = (gcnew System::Windows::Forms::ToolStripButton());
      this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
      this->moveContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->deleteContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->sendToBackContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->contextSeparator = (gcnew System::Windows::Forms::ToolStripSeparator());
      this->lineContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->rectangleContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->circleContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->curveContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->blackContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->redContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->greenContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->blueContextMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
      this->menuStrip1->SuspendLayout();
      this->toolStrip1->SuspendLayout();
      this->contextMenuStrip1->SuspendLayout();
      this->SuspendLayout();
      // 
      // menuStrip1
      // 
      this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->fileToolStripMenuItem, 
        this->editToolStripMenuItem, this->toolsToolStripMenuItem, this->elementToolStripMenuItem, this->colorToolStripMenuItem, this->helpToolStripMenuItem});
      this->menuStrip1->Location = System::Drawing::Point(0, 0);
      this->menuStrip1->Name = L"menuStrip1";
      this->menuStrip1->Size = System::Drawing::Size(355, 24);
      this->menuStrip1->TabIndex = 0;
      this->menuStrip1->Text = L"menuStrip1";
      // 
      // fileToolStripMenuItem
      // 
      this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(10) {this->newToolStripMenuItem, 
        this->openToolStripMenuItem, this->toolStripSeparator, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->toolStripSeparator1, 
        this->printToolStripMenuItem, this->printPreviewToolStripMenuItem, this->toolStripSeparator2, this->exitToolStripMenuItem});
      this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
      this->fileToolStripMenuItem->Size = System::Drawing::Size(35, 20);
      this->fileToolStripMenuItem->Text = L"&File";
      // 
      // newToolStripMenuItem
      // 
      this->newToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"newToolStripMenuItem.Image")));
      this->newToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->newToolStripMenuItem->Name = L"newToolStripMenuItem";
      this->newToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N));
      this->newToolStripMenuItem->Size = System::Drawing::Size(151, 22);
      this->newToolStripMenuItem->Text = L"&New";
      // 
      // openToolStripMenuItem
      // 
      this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openToolStripMenuItem.Image")));
      this->openToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
      this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
      this->openToolStripMenuItem->Size = System::Drawing::Size(151, 22);
      this->openToolStripMenuItem->Text = L"&Open";
      // 
      // toolStripSeparator
      // 
      this->toolStripSeparator->Name = L"toolStripSeparator";
      this->toolStripSeparator->Size = System::Drawing::Size(148, 6);
      // 
      // saveToolStripMenuItem
      // 
      this->saveToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveToolStripMenuItem.Image")));
      this->saveToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
      this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
      this->saveToolStripMenuItem->Size = System::Drawing::Size(151, 22);
      this->saveToolStripMenuItem->Text = L"&Save";
      // 
      // saveAsToolStripMenuItem
      // 
      this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
      this->saveAsToolStripMenuItem->Size = System::Drawing::Size(151, 22);
      this->saveAsToolStripMenuItem->Text = L"Save &As";
      // 
      // toolStripSeparator1
      // 
      this->toolStripSeparator1->Name = L"toolStripSeparator1";
      this->toolStripSeparator1->Size = System::Drawing::Size(148, 6);
      // 
      // printToolStripMenuItem
      // 
      this->printToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"printToolStripMenuItem.Image")));
      this->printToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->printToolStripMenuItem->Name = L"printToolStripMenuItem";
      this->printToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P));
      this->printToolStripMenuItem->Size = System::Drawing::Size(151, 22);
      this->printToolStripMenuItem->Text = L"&Print";
      // 
      // printPreviewToolStripMenuItem
      // 
      this->printPreviewToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"printPreviewToolStripMenuItem.Image")));
      this->printPreviewToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->printPreviewToolStripMenuItem->Name = L"printPreviewToolStripMenuItem";
      this->printPreviewToolStripMenuItem->Size = System::Drawing::Size(151, 22);
      this->printPreviewToolStripMenuItem->Text = L"Print Pre&view";
      // 
      // toolStripSeparator2
      // 
      this->toolStripSeparator2->Name = L"toolStripSeparator2";
      this->toolStripSeparator2->Size = System::Drawing::Size(148, 6);
      // 
      // exitToolStripMenuItem
      // 
      this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
      this->exitToolStripMenuItem->Size = System::Drawing::Size(151, 22);
      this->exitToolStripMenuItem->Text = L"E&xit";
      // 
      // editToolStripMenuItem
      // 
      this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->undoToolStripMenuItem, 
        this->redoToolStripMenuItem, this->toolStripSeparator3, this->cutToolStripMenuItem, this->copyToolStripMenuItem, this->pasteToolStripMenuItem, 
        this->toolStripSeparator4, this->selectAllToolStripMenuItem});
      this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
      this->editToolStripMenuItem->Size = System::Drawing::Size(37, 20);
      this->editToolStripMenuItem->Text = L"&Edit";
      // 
      // undoToolStripMenuItem
      // 
      this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
      this->undoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
      this->undoToolStripMenuItem->Size = System::Drawing::Size(150, 22);
      this->undoToolStripMenuItem->Text = L"&Undo";
      // 
      // redoToolStripMenuItem
      // 
      this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
      this->redoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y));
      this->redoToolStripMenuItem->Size = System::Drawing::Size(150, 22);
      this->redoToolStripMenuItem->Text = L"&Redo";
      // 
      // toolStripSeparator3
      // 
      this->toolStripSeparator3->Name = L"toolStripSeparator3";
      this->toolStripSeparator3->Size = System::Drawing::Size(147, 6);
      // 
      // cutToolStripMenuItem
      // 
      this->cutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"cutToolStripMenuItem.Image")));
      this->cutToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->cutToolStripMenuItem->Name = L"cutToolStripMenuItem";
      this->cutToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X));
      this->cutToolStripMenuItem->Size = System::Drawing::Size(150, 22);
      this->cutToolStripMenuItem->Text = L"Cu&t";
      // 
      // copyToolStripMenuItem
      // 
      this->copyToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"copyToolStripMenuItem.Image")));
      this->copyToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
      this->copyToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
      this->copyToolStripMenuItem->Size = System::Drawing::Size(150, 22);
      this->copyToolStripMenuItem->Text = L"&Copy";
      // 
      // pasteToolStripMenuItem
      // 
      this->pasteToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pasteToolStripMenuItem.Image")));
      this->pasteToolStripMenuItem->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
      this->pasteToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
      this->pasteToolStripMenuItem->Size = System::Drawing::Size(150, 22);
      this->pasteToolStripMenuItem->Text = L"&Paste";
      // 
      // toolStripSeparator4
      // 
      this->toolStripSeparator4->Name = L"toolStripSeparator4";
      this->toolStripSeparator4->Size = System::Drawing::Size(147, 6);
      // 
      // selectAllToolStripMenuItem
      // 
      this->selectAllToolStripMenuItem->Name = L"selectAllToolStripMenuItem";
      this->selectAllToolStripMenuItem->Size = System::Drawing::Size(150, 22);
      this->selectAllToolStripMenuItem->Text = L"Select &All";
      // 
      // toolsToolStripMenuItem
      // 
      this->toolsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->customizeToolStripMenuItem, 
        this->optionsToolStripMenuItem});
      this->toolsToolStripMenuItem->Name = L"toolsToolStripMenuItem";
      this->toolsToolStripMenuItem->Size = System::Drawing::Size(44, 20);
      this->toolsToolStripMenuItem->Text = L"&Tools";
      // 
      // customizeToolStripMenuItem
      // 
      this->customizeToolStripMenuItem->Name = L"customizeToolStripMenuItem";
      this->customizeToolStripMenuItem->Size = System::Drawing::Size(134, 22);
      this->customizeToolStripMenuItem->Text = L"&Customize";
      // 
      // optionsToolStripMenuItem
      // 
      this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
      this->optionsToolStripMenuItem->Size = System::Drawing::Size(134, 22);
      this->optionsToolStripMenuItem->Text = L"&Options";
      // 
      // elementToolStripMenuItem
      // 
      this->elementToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->lineToolStripMenuItem, 
        this->rectangleToolStripMenuItem, this->circleToolStripMenuItem, this->curveToolStripMenuItem});
      this->elementToolStripMenuItem->Name = L"elementToolStripMenuItem";
      this->elementToolStripMenuItem->Size = System::Drawing::Size(57, 20);
      this->elementToolStripMenuItem->Text = L"&Element";
      this->elementToolStripMenuItem->DropDownOpening += gcnew System::EventHandler(this, &Form1::elementToolStripMenuItem_DropDownOpening);
      // 
      // lineToolStripMenuItem
      // 
      this->lineToolStripMenuItem->Checked = true;
      this->lineToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
      this->lineToolStripMenuItem->Name = L"lineToolStripMenuItem";
      this->lineToolStripMenuItem->Size = System::Drawing::Size(133, 22);
      this->lineToolStripMenuItem->Text = L"&Line";
      this->lineToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::lineToolStripMenuItem_Click);
      // 
      // rectangleToolStripMenuItem
      // 
      this->rectangleToolStripMenuItem->Name = L"rectangleToolStripMenuItem";
      this->rectangleToolStripMenuItem->Size = System::Drawing::Size(133, 22);
      this->rectangleToolStripMenuItem->Text = L"&Rectangle";
      this->rectangleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::rectangleToolStripMenuItem_Click);
      // 
      // circleToolStripMenuItem
      // 
      this->circleToolStripMenuItem->Name = L"circleToolStripMenuItem";
      this->circleToolStripMenuItem->Size = System::Drawing::Size(133, 22);
      this->circleToolStripMenuItem->Text = L"&Circle";
      this->circleToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::circleToolStripMenuItem_Click);
      // 
      // curveToolStripMenuItem
      // 
      this->curveToolStripMenuItem->Name = L"curveToolStripMenuItem";
      this->curveToolStripMenuItem->Size = System::Drawing::Size(133, 22);
      this->curveToolStripMenuItem->Text = L"Cur&ve";
      this->curveToolStripMenuItem->DoubleClick += gcnew System::EventHandler(this, &Form1::curveToolStripMenuItem_DoubleClick);
      // 
      // colorToolStripMenuItem
      // 
      this->colorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->blackToolStripMenuItem, 
        this->redToolStripMenuItem, this->greenToolStripMenuItem, this->blueToolStripMenuItem});
      this->colorToolStripMenuItem->Name = L"colorToolStripMenuItem";
      this->colorToolStripMenuItem->Size = System::Drawing::Size(44, 20);
      this->colorToolStripMenuItem->Text = L"&Color";
      this->colorToolStripMenuItem->DropDownOpening += gcnew System::EventHandler(this, &Form1::colorToolStripMenuItem_DropDownOpening);
      // 
      // blackToolStripMenuItem
      // 
      this->blackToolStripMenuItem->Checked = true;
      this->blackToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
      this->blackToolStripMenuItem->Name = L"blackToolStripMenuItem";
      this->blackToolStripMenuItem->Size = System::Drawing::Size(114, 22);
      this->blackToolStripMenuItem->Text = L"Blac&k";
      this->blackToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::blackToolStripMenuItem_Click);
      // 
      // redToolStripMenuItem
      // 
      this->redToolStripMenuItem->Name = L"redToolStripMenuItem";
      this->redToolStripMenuItem->Size = System::Drawing::Size(114, 22);
      this->redToolStripMenuItem->Text = L"&Red";
      this->redToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::redToolStripMenuItem_Click);
      // 
      // greenToolStripMenuItem
      // 
      this->greenToolStripMenuItem->Name = L"greenToolStripMenuItem";
      this->greenToolStripMenuItem->Size = System::Drawing::Size(114, 22);
      this->greenToolStripMenuItem->Text = L"&Green";
      this->greenToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::greenToolStripMenuItem_Click);
      // 
      // blueToolStripMenuItem
      // 
      this->blueToolStripMenuItem->Name = L"blueToolStripMenuItem";
      this->blueToolStripMenuItem->Size = System::Drawing::Size(114, 22);
      this->blueToolStripMenuItem->Text = L"&Blue";
      this->blueToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::blueToolStripMenuItem_Click);
      // 
      // helpToolStripMenuItem
      // 
      this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->contentsToolStripMenuItem, 
        this->indexToolStripMenuItem, this->searchToolStripMenuItem, this->toolStripSeparator5, this->aboutToolStripMenuItem});
      this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
      this->helpToolStripMenuItem->Size = System::Drawing::Size(40, 20);
      this->helpToolStripMenuItem->Text = L"&Help";
      // 
      // contentsToolStripMenuItem
      // 
      this->contentsToolStripMenuItem->Name = L"contentsToolStripMenuItem";
      this->contentsToolStripMenuItem->Size = System::Drawing::Size(129, 22);
      this->contentsToolStripMenuItem->Text = L"&Contents";
      // 
      // indexToolStripMenuItem
      // 
      this->indexToolStripMenuItem->Name = L"indexToolStripMenuItem";
      this->indexToolStripMenuItem->Size = System::Drawing::Size(129, 22);
      this->indexToolStripMenuItem->Text = L"&Index";
      // 
      // searchToolStripMenuItem
      // 
      this->searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
      this->searchToolStripMenuItem->Size = System::Drawing::Size(129, 22);
      this->searchToolStripMenuItem->Text = L"&Search";
      // 
      // toolStripSeparator5
      // 
      this->toolStripSeparator5->Name = L"toolStripSeparator5";
      this->toolStripSeparator5->Size = System::Drawing::Size(126, 6);
      // 
      // aboutToolStripMenuItem
      // 
      this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
      this->aboutToolStripMenuItem->Size = System::Drawing::Size(129, 22);
      this->aboutToolStripMenuItem->Text = L"&About...";
      // 
      // toolStrip1
      // 
      this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(15) {this->newToolStripButton, 
        this->openToolStripButton, this->saveToolStripButton, this->printToolStripButton, this->toolStripSeparator6, this->toolStripSeparator7, 
        this->toolStripLineButton, this->rectangleToolStripButton, this->circleToolStripButton, this->curveToolStripButton, this->toolStripSeparator8, 
        this->blackToolStripButton, this->redToolStripButton, this->greenToolStripButton, this->blueToolStripButton});
      this->toolStrip1->Location = System::Drawing::Point(0, 24);
      this->toolStrip1->Name = L"toolStrip1";
      this->toolStrip1->Size = System::Drawing::Size(355, 25);
      this->toolStrip1->TabIndex = 1;
      this->toolStrip1->Text = L"toolStrip1";
      // 
      // newToolStripButton
      // 
      this->newToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->newToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"newToolStripButton.Image")));
      this->newToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->newToolStripButton->Name = L"newToolStripButton";
      this->newToolStripButton->Size = System::Drawing::Size(23, 22);
      this->newToolStripButton->Text = L"&New";
      // 
      // openToolStripButton
      // 
      this->openToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->openToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"openToolStripButton.Image")));
      this->openToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->openToolStripButton->Name = L"openToolStripButton";
      this->openToolStripButton->Size = System::Drawing::Size(23, 22);
      this->openToolStripButton->Text = L"&Open";
      // 
      // saveToolStripButton
      // 
      this->saveToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->saveToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"saveToolStripButton.Image")));
      this->saveToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->saveToolStripButton->Name = L"saveToolStripButton";
      this->saveToolStripButton->Size = System::Drawing::Size(23, 22);
      this->saveToolStripButton->Text = L"&Save";
      // 
      // printToolStripButton
      // 
      this->printToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->printToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"printToolStripButton.Image")));
      this->printToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->printToolStripButton->Name = L"printToolStripButton";
      this->printToolStripButton->Size = System::Drawing::Size(23, 22);
      this->printToolStripButton->Text = L"&Print";
      // 
      // toolStripSeparator6
      // 
      this->toolStripSeparator6->Name = L"toolStripSeparator6";
      this->toolStripSeparator6->Size = System::Drawing::Size(6, 25);
      // 
      // toolStripSeparator7
      // 
      this->toolStripSeparator7->Name = L"toolStripSeparator7";
      this->toolStripSeparator7->Size = System::Drawing::Size(6, 25);
      // 
      // toolStripLineButton
      // 
      this->toolStripLineButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->toolStripLineButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripLineButton.Image")));
      this->toolStripLineButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->toolStripLineButton->Name = L"toolStripLineButton";
      this->toolStripLineButton->Size = System::Drawing::Size(23, 22);
      this->toolStripLineButton->Text = L"toolStripButton1";
      this->toolStripLineButton->ToolTipText = L"Draw lines";
      this->toolStripLineButton->Click += gcnew System::EventHandler(this, &Form1::lineToolStripMenuItem_Click);
      // 
      // rectangleToolStripButton
      // 
      this->rectangleToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->rectangleToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"rectangleToolStripButton.Image")));
      this->rectangleToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->rectangleToolStripButton->Name = L"rectangleToolStripButton";
      this->rectangleToolStripButton->Size = System::Drawing::Size(23, 22);
      this->rectangleToolStripButton->Text = L"toolStripButton1";
      this->rectangleToolStripButton->ToolTipText = L"Draw rectangles";
      this->rectangleToolStripButton->Click += gcnew System::EventHandler(this, &Form1::rectangleToolStripMenuItem_Click);
      // 
      // circleToolStripButton
      // 
      this->circleToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->circleToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"circleToolStripButton.Image")));
      this->circleToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->circleToolStripButton->Name = L"circleToolStripButton";
      this->circleToolStripButton->Size = System::Drawing::Size(23, 22);
      this->circleToolStripButton->Text = L"toolStripButton1";
      this->circleToolStripButton->ToolTipText = L"Draw circles";
      this->circleToolStripButton->Click += gcnew System::EventHandler(this, &Form1::circleToolStripMenuItem_Click);
      // 
      // curveToolStripButton
      // 
      this->curveToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->curveToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"curveToolStripButton.Image")));
      this->curveToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->curveToolStripButton->Name = L"curveToolStripButton";
      this->curveToolStripButton->Size = System::Drawing::Size(23, 22);
      this->curveToolStripButton->Text = L"toolStripButton1";
      this->curveToolStripButton->ToolTipText = L"Draw curves";
      this->curveToolStripButton->Click += gcnew System::EventHandler(this, &Form1::curveToolStripMenuItem_DoubleClick);
      // 
      // toolStripSeparator8
      // 
      this->toolStripSeparator8->Name = L"toolStripSeparator8";
      this->toolStripSeparator8->Size = System::Drawing::Size(6, 25);
      // 
      // blackToolStripButton
      // 
      this->blackToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->blackToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"blackToolStripButton.Image")));
      this->blackToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->blackToolStripButton->Name = L"blackToolStripButton";
      this->blackToolStripButton->Size = System::Drawing::Size(23, 22);
      this->blackToolStripButton->Text = L"toolStripButton1";
      this->blackToolStripButton->ToolTipText = L"Draw in black";
      this->blackToolStripButton->Click += gcnew System::EventHandler(this, &Form1::blackToolStripMenuItem_Click);
      // 
      // redToolStripButton
      // 
      this->redToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->redToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"redToolStripButton.Image")));
      this->redToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->redToolStripButton->Name = L"redToolStripButton";
      this->redToolStripButton->Size = System::Drawing::Size(23, 22);
      this->redToolStripButton->Text = L"toolStripButton1";
      this->redToolStripButton->ToolTipText = L"Draw in red";
      this->redToolStripButton->Click += gcnew System::EventHandler(this, &Form1::redToolStripMenuItem_Click);
      // 
      // greenToolStripButton
      // 
      this->greenToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->greenToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"greenToolStripButton.Image")));
      this->greenToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->greenToolStripButton->Name = L"greenToolStripButton";
      this->greenToolStripButton->Size = System::Drawing::Size(23, 22);
      this->greenToolStripButton->Text = L"toolStripButton1";
      this->greenToolStripButton->ToolTipText = L"Draw in green";
      this->greenToolStripButton->Click += gcnew System::EventHandler(this, &Form1::greenToolStripMenuItem_Click);
      // 
      // blueToolStripButton
      // 
      this->blueToolStripButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
      this->blueToolStripButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"blueToolStripButton.Image")));
      this->blueToolStripButton->ImageTransparentColor = System::Drawing::Color::Magenta;
      this->blueToolStripButton->Name = L"blueToolStripButton";
      this->blueToolStripButton->Size = System::Drawing::Size(23, 22);
      this->blueToolStripButton->Text = L"toolStripButton1";
      this->blueToolStripButton->ToolTipText = L"Draw in blue";
      this->blueToolStripButton->Click += gcnew System::EventHandler(this, &Form1::blueToolStripMenuItem_Click);
      // 
      // contextMenuStrip1
      // 
      this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(12) {this->moveContextMenuItem, 
        this->deleteContextMenuItem, this->sendToBackContextMenuItem, this->contextSeparator, this->lineContextMenuItem, this->rectangleContextMenuItem, 
        this->circleContextMenuItem, this->curveContextMenuItem, this->blackContextMenuItem, this->redContextMenuItem, this->greenContextMenuItem, 
        this->blueContextMenuItem});
      this->contextMenuStrip1->Name = L"contextMenuStrip1";
      this->contextMenuStrip1->Size = System::Drawing::Size(152, 252);
      this->contextMenuStrip1->Opening += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::contextMenuStrip1_Opening);
      // 
      // moveContextMenuItem
      // 
      this->moveContextMenuItem->Name = L"moveContextMenuItem";
      this->moveContextMenuItem->Size = System::Drawing::Size(151, 22);
      this->moveContextMenuItem->Text = L"Move";
      this->moveContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::moveContextMenuItem_Click);
      // 
      // deleteContextMenuItem
      // 
      this->deleteContextMenuItem->Name = L"deleteContextMenuItem";
      this->deleteContextMenuItem->Size = System::Drawing::Size(151, 22);
      this->deleteContextMenuItem->Text = L"Delete";
      this->deleteContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::deleteContextMenuItem_Click);
      // 
      // sendToBackContextMenuItem
      // 
      this->sendToBackContextMenuItem->Name = L"sendToBackContextMenuItem";
      this->sendToBackContextMenuItem->Size = System::Drawing::Size(151, 22);
      this->sendToBackContextMenuItem->Text = L"Send-To-Back";
      this->sendToBackContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::sendToBackContextMenuItem_Click);
      // 
      // contextSeparator
      // 
      this->contextSeparator->Name = L"contextSeparator";
      this->contextSeparator->Size = System::Drawing::Size(148, 6);
      // 
      // lineContextMenuItem
      // 
      this->lineContextMenuItem->Name = L"lineContextMenuItem";
      this->lineContextMenuItem->Size = System::Drawing::Size(151, 22);
      this->lineContextMenuItem->Text = L"Line";
      this->lineContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::lineToolStripMenuItem_Click);
      // 
      // rectangleContextMenuItem
      // 
      this->rectangleContextMenuItem->Name = L"rectangleContextMenuItem";
      this->rectangleContextMenuItem->Size = System::Drawing::Size(151, 22);
      this->rectangleContextMenuItem->Text = L"Rectangle";
      this->rectangleContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::rectangleToolStripMenuItem_Click);
      // 
      // circleContextMenuItem
      // 
      this->circleContextMenuItem->Name = L"circleContextMenuItem";
      this->circleContextMenuItem->Size = System::Drawing::Size(151, 22);
      this->circleContextMenuItem->Text = L"Circle";
      this->circleContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::circleToolStripMenuItem_Click);
      // 
      // curveContextMenuItem
      // 
      this->curveContextMenuItem->Name = L"curveContextMenuItem";
      this->curveContextMenuItem->Size = System::Drawing::Size(151, 22);
      this->curveContextMenuItem->Text = L"Curve";
      this->curveContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::curveToolStripMenuItem_DoubleClick);
      // 
      // blackContextMenuItem
      // 
      this->blackContextMenuItem->Name = L"blackContextMenuItem";
      this->blackContextMenuItem->Size = System::Drawing::Size(151, 22);
      this->blackContextMenuItem->Text = L"Black";
      this->blackContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::blackToolStripMenuItem_Click);
      // 
      // redContextMenuItem
      // 
      this->redContextMenuItem->Name = L"redContextMenuItem";
      this->redContextMenuItem->Size = System::Drawing::Size(151, 22);
      this->redContextMenuItem->Text = L"Red";
      this->redContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::redToolStripMenuItem_Click);
      // 
      // greenContextMenuItem
      // 
      this->greenContextMenuItem->Name = L"greenContextMenuItem";
      this->greenContextMenuItem->Size = System::Drawing::Size(151, 22);
      this->greenContextMenuItem->Text = L"Green";
      this->greenContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::greenToolStripMenuItem_Click);
      // 
      // blueContextMenuItem
      // 
      this->blueContextMenuItem->Name = L"blueContextMenuItem";
      this->blueContextMenuItem->Size = System::Drawing::Size(151, 22);
      this->blueContextMenuItem->Text = L"Blue";
      this->blueContextMenuItem->Click += gcnew System::EventHandler(this, &Form1::blueToolStripMenuItem_Click);
      // 
      // Form1
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->BackColor = System::Drawing::SystemColors::ControlLightLight;
      this->ClientSize = System::Drawing::Size(355, 285);
      this->ContextMenuStrip = this->contextMenuStrip1;
      this->Controls->Add(this->toolStrip1);
      this->Controls->Add(this->menuStrip1);
      this->MainMenuStrip = this->menuStrip1;
      this->Name = L"Form1";
      this->Text = L"CLR Sketcher";
      this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
      this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
      this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
      this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
      this->menuStrip1->ResumeLayout(false);
      this->menuStrip1->PerformLayout();
      this->toolStrip1->ResumeLayout(false);
      this->toolStrip1->PerformLayout();
      this->contextMenuStrip1->ResumeLayout(false);
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion
  private: System::Void lineToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
   elementType = ElementType::LINE;          }
private: System::Void rectangleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
    elementType = ElementType::RECTANGLE;       }
private: System::Void circleToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
   elementType = ElementType::CIRCLE;        }
private: System::Void curveToolStripMenuItem_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
   elementType = ElementType::CURVE;        }
private: System::Void blackToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
            color = Color::Black;        }
private: System::Void redToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
            color = Color::Red;        }
private: System::Void greenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
            color = Color::Green;        }
private: System::Void blueToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
            color = Color::Blue;        }
private: System::Void colorToolStripMenuItem_DropDownOpening(System::Object^  sender, System::EventArgs^  e) {
  blackToolStripMenuItem->Checked = color == Color::Black;
  redToolStripMenuItem->Checked = color == Color::Red;
  greenToolStripMenuItem->Checked = color == Color::Green;
  blueToolStripMenuItem->Checked = color == Color::Blue;
         }
private: System::Void elementToolStripMenuItem_DropDownOpening(System::Object^  sender, System::EventArgs^  e) {
  lineToolStripMenuItem->Checked = elementType == ElementType::LINE;
  rectangleToolStripMenuItem->Checked = elementType == ElementType::RECTANGLE;
  circleToolStripMenuItem->Checked = elementType == ElementType::CIRCLE;
  curveToolStripMenuItem->Checked = elementType == ElementType::CURVE;
        }
         // Current element type
         ElementType elementType;
         // Current drawing color
         Color color;
private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
  Graphics^ g = e->Graphics;
  sketch->Draw(g);
  if(tempElement)
    tempElement->Draw(g);
}
         // Records when drawing an element is in progress
         bool drawing;
         // Records the initial mouse cursor position
         Point firstPoint;
private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
  if(e->Button == System::Windows::Forms::MouseButtons::Left)
  {
    if(mode == Mode::Normal)
      drawing = true;
    firstPoint = e->Location;
  }
         }
private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
   if(drawing)
  {
    if(tempElement)
      Invalidate(tempElement->Bound);  // The old element region
    switch(elementType)
    {
      case ElementType::LINE:
        tempElement = gcnew Line(color, firstPoint, e->Location);
        break;
      case ElementType::RECTANGLE:
        tempElement = gcnew Rectangle(color, firstPoint, e->Location);
        break;
      case ElementType::CIRCLE:
        tempElement = gcnew Circle(color, firstPoint, e->Location);
        break;
      case ElementType::CURVE:
        if(tempElement)
          safe_cast<Curve^>(tempElement)->Add(e->Location);
        else
          tempElement = gcnew Curve(color, firstPoint, e->Location);
        break;
    }
    Invalidate(tempElement->Bound);    // The new element region
    Update();
   }
   else if(mode == Mode::Normal)
   {
     Element^ element = sketch->HitElement(e->Location);
     if(highlightedElement == element)
       return;
     if(highlightedElement)
     {
       Invalidate(highlightedElement->Bound);
       highlightedElement->highlighted = false;
       highlightedElement = nullptr;
     }
     if(element)
     {
       highlightedElement = element;
       highlightedElement->highlighted = true;
       Invalidate(highlightedElement->Bound);
     }
     Update();
    }
   else if(mode == Mode::Move && e->Button == System::Windows::Forms::MouseButtons::Left)
   {  // Move the highlighted element
     if(highlightedElement)
     {
        Invalidate(highlightedElement->Bound);    // Region before move
        highlightedElement->Move(e->X - firstPoint.X, e->Y - firstPoint.Y);
       firstPoint = e->Location;
       Invalidate(highlightedElement->Bound);     // Region after move
       Update();
     }
   }
   else if(mode == Mode::Rotate)
   {
   }
 }

private: System::Void Form1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
  if(!drawing)
  {
    mode = Mode::Normal;
    return;
  }
  if(tempElement)
  {
    sketch->Add(tempElement);
    tempElement = nullptr;
   Invalidate();
  }
  drawing = false;
         }
         // Temporary store for the element being drawn
         Element^ tempElement;
         // Stores the current sketch
         Sketch^ sketch;
protected:
  // The currently highlighted element
  Element^ highlightedElement;
private: System::Void contextMenuStrip1_Opening(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
 contextMenuStrip1->Items->Clear();    // Remove existing items
 if(highlightedElement)
 {
   contextMenuStrip1->Items->Add(moveContextMenuItem);
   contextMenuStrip1->Items->Add(deleteContextMenuItem);
   contextMenuStrip1->Items->Add(sendToBackContextMenuItem);
 }
 else
 {
    contextMenuStrip1->Items->Add(lineContextMenuItem);
    contextMenuStrip1->Items->Add(rectangleContextMenuItem);
    contextMenuStrip1->Items->Add(circleContextMenuItem);
    contextMenuStrip1->Items->Add(curveContextMenuItem);
    contextMenuStrip1->Items->Add(contextSeparator);
    contextMenuStrip1->Items->Add(blackContextMenuItem);
    contextMenuStrip1->Items->Add(redContextMenuItem);
    contextMenuStrip1->Items->Add(greenContextMenuItem);
    contextMenuStrip1->Items->Add(blueContextMenuItem);

    // Set checks for the menu items
    blackContextMenuItem->Checked = color == Color::Black;
    redContextMenuItem->Checked = color == Color::Red;
    greenContextMenuItem->Checked = color == Color::Green;
    blueContextMenuItem->Checked = color == Color::Blue;
    lineContextMenuItem->Checked = elementType == ElementType::LINE;
    rectangleContextMenuItem->Checked = elementType == ElementType::RECTANGLE;
    circleContextMenuItem->Checked = elementType == ElementType::CIRCLE;
    curveContextMenuItem->Checked = elementType == ElementType::CURVE;
 }

        }

private: System::Void deleteContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
           if(highlightedElement)
           {
             sketch->Delete(highlightedElement);
             Invalidate(highlightedElement->Bound);
             highlightedElement = nullptr;
             Update();
           }

         }
private: System::Void sendToBackContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
  if(highlightedElement)
  {
    sketch->Add(sketch->Delete(highlightedElement));
    highlightedElement->highlighted = false;
    Invalidate(highlightedElement->Bound);
    highlightedElement = nullptr;
    Update();
  }
}
private: System::Void moveContextMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
           mode = Mode::Move;
         }
         Mode mode;
};
}

