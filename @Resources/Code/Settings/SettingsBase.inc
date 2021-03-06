[Rainmeter]
MouseActionCursor=0
Update=50

; ---------------------------------------------
; base for all the Settings' panels
; ---------------------------------------------

[Variables]

; code snippets
@includeGlobal=#@#Code/Global/GlobalData.inc
@includeColors=#@#Code/Global/Colors[#WindowsColorScheme].inc
@includeData=#@#Code/Settings/SettingsData.inc
@includeStyles=#@#Code/Settings/SettingsStyles.inc

; local variables
SectionName=SectionName
PageName=PageName

; toggles
toggleNavigationPanel=1


; ---------------------------------------------
;  measures
; ---------------------------------------------

; parsing the profile picture file

[mPictureFolder]
Measure=Plugin
Plugin=FileView
Path="%AppData%\Microsoft\Windows\AccountPictures"
ShowDotDot=0
ShowFolder=0
HideExtensions=1
SortType=Date
Count=1
FinishAction=["#@#Addons\AccountPicConverter.exe" "[mPictureFile]"]
Disabled=1

[mPictureFile]
Measure=Plugin
Plugin=FileView
Path=[mPictureFolder]
Index=1
Type=FilePath

; parsing converted image

[mConvertedFolder]
Measure=Plugin
Plugin=FileView
Path="#@#Addons"
ShowDotDot=0
ShowFolder=0
Extensions="jpg;bmp"
SortType=Size
SortAscending=0
Count=1

[mConvertedFile]
Measure=Plugin
Plugin=FileView
Path=[mConvertedFolder]
Index=1
Type=FilePath

; mouse position for Reveal-like effect

[mMousePosition]
Measure=Plugin
Plugin=MouseXY
Dimension=X
MaxValue=#SCREENAREAWIDTH#
Disabled=1

[mMoveEffect]
Measure=Calc
Formula=(mMousePosition - #CURRENTCONFIGX# - #WindowBorderThickness# - #LeftPanelMarginSmall#)
DynamicVariables=1
Disabled=1
OnChangeAction=[!UpdateMeterGroup grEffectReveal][!Redraw]







; ---------------------------------------------
;  window background + top bar elements
; ---------------------------------------------

[Background]
Meter=Shape
MeterStyle=stWindowBackground

[Border]
Meter=Shape
MeterStyle=stWindowBorder

; menu button

[MenuHitbox]
Meter=Shape
MeterStyle=stNavHitbox
MouseOverAction=[!EnableMeasure mMousePosition][!EnableMeasure mMoveEffect][!ShowMeterGroup grMenu]
MouseLeaveAction=[!DisableMeasure mMousePosition][!DisableMeasure mMoveEffect][!HideMeterGroup grMenu]
LeftMouseUpAction=[!WriteKeyValue Variables toggleNavigationPanel (1-#toggleNavigationPanel#) "#@#Code/Settings/SettingsBase.inc"][!Refresh]

[MenuButton]
Meter=Shape
MeterStyle=stNavButton
Group=grMenu

[MenuBorder]
Meter=Shape
MeterStyle=stNavBorder
Group=grMenu

[MenuGlyph]
Meter=String
MeterStyle=stNavGlyph
Text=[\xf4e1]

[MenuEffect]
Meter=Shape
MeterStyle=stNavEffect
Container=MenuButton

; close button

[WindowTitle]
Meter=String
MeterStyle=stWindowTitle
Text=Settings
















[CloseIcon]
;Meter=String
MeterStyle=stNavigationGlyph
X=([Background:XW] - #NavGlyphOffsetLR#)
Text=[\xf369]
LeftMouseUpAction=[!DeactivateConfig]

[MaximizeIcon]
;Meter=String
MeterStyle=stNavigationGlyph
Text=[\xf916]

[MinimizeIcon]
;Meter=String
MeterStyle=stNavigationGlyph
Text=[\xf6f8]

; ---------------------------------------------
; header
; ---------------------------------------------

[ProfileMask]
Meter=Shape
MeterStyle=stProfileMask

[ProfilePicture]
Meter=Image
MeasureName=mConvertedFile
W=(2*#ProfilePictureR#)
H=(2*#ProfilePictureR#)
AntiAlias=1
Container=ProfileMask

[ProfileName]
Meter=String
MeterStyle=stProfileName
Text=Todd Howard

[ProfileInfo]
Meter=String
MeterStyle=stProfileInfo
Text=buyskyrim@bethesda.com

[SectionName]
Meter=String
MeterStyle=stPageTitleText
FontColor=#colorWindowFont2#
Text=#SectionName#

[SectionGlyph]
Meter=String
MeterStyle=stPageTitleGlyph

[PageName]
Meter=String
MeterStyle=stPageTitleText
X=#PageTitleGlyphOffsetLR#r
Text=#PageName#

; ---------------------------------------------
; left panel
; ---------------------------------------------

[Section1Label]
Meter=String
MeterStyle=stSectionLabel
Y=#SectionStack1#
Text=Personalization

; page 1 - colors

[Page1Hitbox]
Meter=Shape
MeterStyle=stPageHitbox
MouseOverAction=[!EnableMeasure mMousePosition][!EnableMeasure mMoveEffect][!ShowMeterGroup grPage1]
MouseLeaveAction=[!DisableMeasure mMousePosition][!DisableMeasure mMoveEffect][!HideMeterGroup grPage1]
LeftMouseUpAction=[!ActivateConfig "#CURRENTCONFIG#" "SettingsColors.ini"]

[Page1Button]
Meter=Shape
MeterStyle=stPageButton
Group=grPage1

[Page1Border]
Meter=Shape
MeterStyle=stPageBorder
Group=grPage1

[Page1Indicator]
Meter=Shape
MeterStyle=stPageIndicator

[Page1Icon]
Meter=Image
MeterStyle=stPageIcon
ImageName=#@#Images/Settings/colors.png

[Page1Label]
Meter=String
MeterStyle=stPageLabel
Text=Colors

[Page1Effect]
Meter=Shape
MeterStyle=stPageEffect
Container=Page1Button

; page 2 - effects

[Page2Hitbox]
Meter=Shape
MeterStyle=stPageHitbox
MouseOverAction=[!EnableMeasure mMousePosition][!EnableMeasure mMoveEffect][!ShowMeterGroup grPage2]
MouseLeaveAction=[!DisableMeasure mMousePosition][!DisableMeasure mMoveEffect][!HideMeterGroup grPage2]
LeftMouseUpAction=[!ActivateConfig "#CURRENTCONFIG#" "SettingsEffects.ini"]

[Page2Button]
Meter=Shape
MeterStyle=stPageButton
Group=grPage2

[Page2Border]
Meter=Shape
MeterStyle=stPageBorder
Group=grPage2

[Page2Indicator]
Meter=Shape
MeterStyle=stPageIndicator

[Page2Icon]
Meter=Image
MeterStyle=stPageIcon
ImageName=#@#Images/Settings/effects.png

[Page2Label]
Meter=String
MeterStyle=stPageLabel
Text=Effects

[Page2Effect]
Meter=Shape
MeterStyle=stPageEffect
Container=Page2Button

; ---------------------------------------------

[Section2Label]
Meter=String
MeterStyle=stSectionLabel
Y=#SectionStack2#
Text=Widgets

; page 3 - taskbar

[Page3Hitbox]
Meter=Shape
MeterStyle=stPageHitbox
MouseOverAction=[!EnableMeasure mMousePosition][!EnableMeasure mMoveEffect][!ShowMeterGroup grPage3]
MouseLeaveAction=[!DisableMeasure mMousePosition][!DisableMeasure mMoveEffect][!HideMeterGroup grPage3]

[Page3Button]
Meter=Shape
MeterStyle=stPageButton
Group=grPage3

[Page3Border]
Meter=Shape
MeterStyle=stPageBorder
Group=grPage3

[Page3Indicator]
Meter=Shape
MeterStyle=stPageIndicator

[Page3Icon]
Meter=Image
MeterStyle=stPageIcon
ImageName=#@#Images/Settings/taskbar.png

[Page3Label]
Meter=String
MeterStyle=stPageLabel
Text=Taskbar

[Page3Effect]
Meter=Shape
MeterStyle=stPageEffect
Container=Page3Button

; page 4 - start menu

[Page4Hitbox]
Meter=Shape
MeterStyle=stPageHitbox
MouseOverAction=[!EnableMeasure mMousePosition][!EnableMeasure mMoveEffect][!ShowMeterGroup grPage4]
MouseLeaveAction=[!DisableMeasure mMousePosition][!DisableMeasure mMoveEffect][!HideMeterGroup grPage4]

[Page4Button]
Meter=Shape
MeterStyle=stPageButton
Group=grPage4

[Page4Border]
Meter=Shape
MeterStyle=stPageBorder
Group=grPage4

[Page4Indicator]
Meter=Shape
MeterStyle=stPageIndicator

[Page4Icon]
Meter=Image
MeterStyle=stPageIcon
ImageName=#@#Images/Settings/start.png

[Page4Label]
Meter=String
MeterStyle=stPageLabel
Text=Start menu

[Page4Effect]
Meter=Shape
MeterStyle=stPageEffect
Container=Page4Button

; page 5 - apps

[Page5Hitbox]
Meter=Shape
MeterStyle=stPageHitbox
MouseOverAction=[!EnableMeasure mMousePosition][!EnableMeasure mMoveEffect][!ShowMeterGroup grPage5]
MouseLeaveAction=[!DisableMeasure mMousePosition][!DisableMeasure mMoveEffect][!HideMeterGroup grPage5]

[Page5Button]
Meter=Shape
MeterStyle=stPageButton
Group=grPage5

[Page5Border]
Meter=Shape
MeterStyle=stPageBorder
Group=grPage5

[Page5Indicator]
Meter=Shape
MeterStyle=stPageIndicator

[Page5Icon]
Meter=Image
MeterStyle=stPageIcon
ImageName=#@#Images/Settings/apps.png

[Page5Label]
Meter=String
MeterStyle=stPageLabel
Text=Applications

[Page5Effect]
Meter=Shape
MeterStyle=stPageEffect
Container=Page5Button

; page 6 - clipboard

[Page6Hitbox]
Meter=Shape
MeterStyle=stPageHitbox
MouseOverAction=[!EnableMeasure mMousePosition][!EnableMeasure mMoveEffect][!ShowMeterGroup grPage6]
MouseLeaveAction=[!DisableMeasure mMousePosition][!DisableMeasure mMoveEffect][!HideMeterGroup grPage6]

[Page6Button]
Meter=Shape
MeterStyle=stPageButton
Group=grPage6

[Page6Border]
Meter=Shape
MeterStyle=stPageBorder
Group=grPage6

[Page6Indicator]
Meter=Shape
MeterStyle=stPageIndicator

[Page6Icon]
Meter=Image
MeterStyle=stPageIcon
ImageName=#@#Images/Settings/clipboard.png

[Page6Label]
Meter=String
MeterStyle=stPageLabel
Text=Clipboard

[Page6Effect]
Meter=Shape
MeterStyle=stPageEffect
Container=Page6Button

; ---------------------------------------------

[Section3Label]
Meter=String
MeterStyle=stSectionLabel
Y=#SectionStack3#
Text=About

; page M - about Flux

[PageMHitbox]
Meter=Shape
MeterStyle=stPageHitbox
MouseOverAction=[!EnableMeasure mMousePosition][!EnableMeasure mMoveEffect][!ShowMeterGroup grPageM]
MouseLeaveAction=[!DisableMeasure mMousePosition][!DisableMeasure mMoveEffect][!HideMeterGroup grPageM]

[PageMButton]
Meter=Shape
MeterStyle=stPageButton
Group=grPageM

[PageMBorder]
Meter=Shape
MeterStyle=stPageBorder
Group=grPageM

[PageMIndicator]
Meter=Shape
MeterStyle=stPageIndicator

[PageMIcon]
Meter=Image
MeterStyle=stPageIcon
ImageName=#@#Images/Settings/flux.png

[PageMLabel]
Meter=String
MeterStyle=stPageLabel
Text=Flux

[PageMEffect]
Meter=Shape
MeterStyle=stPageEffect
Container=PageMButton

; page N - about Rainmeter

[PageNHitbox]
Meter=Shape
MeterStyle=stPageHitbox
MouseOverAction=[!EnableMeasure mMousePosition][!EnableMeasure mMoveEffect][!ShowMeterGroup grPageN]
MouseLeaveAction=[!DisableMeasure mMousePosition][!DisableMeasure mMoveEffect][!HideMeterGroup grPageN]

[PageNButton]
Meter=Shape
MeterStyle=stPageButton
Group=grPageN

[PageNBorder]
Meter=Shape
MeterStyle=stPageBorder
Group=grPageN

[PageNIndicator]
Meter=Shape
MeterStyle=stPageIndicator

[PageNIcon]
Meter=Image
MeterStyle=stPageIcon
ImageName=#@#Images/Settings/rain.png

[PageNLabel]
Meter=String
MeterStyle=stPageLabel
Text=Rainmeter

[PageNEffect]
Meter=Shape
MeterStyle=stPageEffect
Container=PageNButton
