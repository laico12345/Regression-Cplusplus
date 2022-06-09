object Form1: TForm1
  Left = 425
  Top = 104
  Width = 852
  Height = 665
  Caption = 'Regression Analysis'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 32
    Top = 72
    Width = 95
    Height = 19
    Caption = 'Learning Rate : '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 416
    Top = 72
    Width = 32
    Height = 19
    Caption = 'Iter : '
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 32
    Top = 16
    Width = 185
    Height = 41
    Caption = 'Read'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object edtRate: TEdit
    Left = 128
    Top = 72
    Width = 89
    Height = 27
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = '0.01'
  end
  object btnGD: TButton
    Left = 416
    Top = 16
    Width = 155
    Height = 41
    Caption = 'Regression'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = btnGDClick
  end
  object Chart1: TChart
    Left = 32
    Top = 112
    Width = 537
    Height = 457
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'TChart')
    Title.Visible = False
    BottomAxis.ExactDateTime = False
    BottomAxis.Increment = 0.5
    BottomAxis.Title.Caption = 'x'
    BottomAxis.Title.Font.Charset = ANSI_CHARSET
    BottomAxis.Title.Font.Color = clBlack
    BottomAxis.Title.Font.Height = -16
    BottomAxis.Title.Font.Name = 'Times New Roman'
    BottomAxis.Title.Font.Style = []
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.ExactDateTime = False
    LeftAxis.Increment = 0.5
    LeftAxis.Maximum = 3
    LeftAxis.Minimum = -1
    LeftAxis.Title.Angle = 360
    LeftAxis.Title.Caption = 'y'
    LeftAxis.Title.Font.Charset = ANSI_CHARSET
    LeftAxis.Title.Font.Color = clBlack
    LeftAxis.Title.Font.Height = -16
    LeftAxis.Title.Font.Name = 'Times New Roman'
    LeftAxis.Title.Font.Style = []
    LeftAxis.TitleSize = 4
    RightAxis.Automatic = False
    RightAxis.AutomaticMaximum = False
    RightAxis.AutomaticMinimum = False
    View3D = False
    View3DWalls = False
    Color = clWhite
    TabOrder = 3
    object Series1: TPointSeries
      Marks.ArrowLength = 0
      Marks.Visible = False
      SeriesColor = clRed
      Title = 'Sample'
      Pointer.Brush.Color = clRed
      Pointer.Dark3D = False
      Pointer.Draw3D = False
      Pointer.InflateMargins = False
      Pointer.Style = psCircle
      Pointer.Visible = True
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series2: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clBlue
      Title = 'Nonlinear'
      Dark3D = False
      LinePen.Width = 3
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series3: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clGreen
      Title = 'Linear'
      LinePen.Width = 3
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
    object Series4: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = 16711808
      Title = 'Analytic'
      Dark3D = False
      LinePen.Width = 3
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object urlOpen: TEdit
    Left = 32
    Top = 576
    Width = 537
    Height = 27
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object Edit1: TEdit
    Left = 448
    Top = 72
    Width = 121
    Height = 27
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    Text = '2000'
  end
  object ListBox1: TListBox
    Left = 576
    Top = 64
    Width = 217
    Height = 193
    ItemHeight = 13
    TabOrder = 6
  end
  object RadioGroup1: TRadioGroup
    Left = 224
    Top = 8
    Width = 185
    Height = 97
    Caption = 'Regression'
    Items.Strings = (
      'Nonlinear Regression'
      'Linear Regression'
      'Linear Analytic expression')
    TabOrder = 7
  end
  object ListBox2: TListBox
    Left = 576
    Top = 264
    Width = 217
    Height = 209
    ItemHeight = 13
    TabOrder = 8
  end
  object Button2: TButton
    Left = 576
    Top = 16
    Width = 217
    Height = 41
    Caption = 'Save and Clear'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = Button2Click
  end
  object ListBox3: TListBox
    Left = 576
    Top = 480
    Width = 217
    Height = 121
    ItemHeight = 13
    TabOrder = 10
  end
  object OpenDialog1: TOpenDialog
  end
end
