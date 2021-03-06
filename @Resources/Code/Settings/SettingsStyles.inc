; ---------------------------------------------
; styles used in the Settings skin
; ---------------------------------------------


; ---------------------------------------------
; general window styles
; ---------------------------------------------

[stWindowBackground]
Shape=Rectangle #WindowBorderThickness#,#WindowBorderThickness#,(#WindowWidthTotal#-(2*#WindowBorderThickness#)),(#WindowHeightTotal#-(2*#WindowBorderThickness#)),#WindowCornerRadius#,#WindowCornerRadius# | Extend stWindowBackground
stWindowBackground = Fill Color #colorWindowBackground#,#valueWindowOpacity# | StrokeWidth 0
DynamicVariables=1

[stWindowBorder]
Shape=Rectangle 0,0,#WindowWidthTotal#,#WindowHeightTotal#,#WindowCornerRadius#,#WindowCornerRadius# | Extend stWindowBorder
Shape2=Rectangle #WindowBorderThickness#,#WindowBorderThickness#,(#WindowWidthTotal#-(2*#WindowBorderThickness#)),(#WindowHeightTotal#-(2*#WindowBorderThickness#)),#WindowCornerRadius#,#WindowCornerRadius#
Shape3=Combine Shape | Exclude Shape2
stWindowBorder = Fill Color #colorWindowBorder# | StrokeWidth 0
DynamicVariables=1

[stLeftContainer]
X=0
Y=0
Shape=Rectangle 0,(#HeaderStack# - #ProfilePictureR#),#LeftPanelWidth#,(#WindowHeightTotal# - #HeaderStack# + #ProfilePictureR#) | Extend stLeftContainer
stLeftContainer = Fill Color 0,0,250,50 | StrokeWidth 0
AntiAlias=1
DynamicVariables=1

; ---------------------------------------------
; top bar elements
; ---------------------------------------------

[stNavHitbox]
X=((#TitleBarHeight# - #NavButtonSize#)/2)r
Y=((#TitleBarHeight# - #NavButtonSize#)/2)r
Shape=Rectangle 0,0,#NavButtonSize#,#NavButtonSize#,#ObjectCornerRadius#,#ObjectCornerRadius# | Extend stNavHitbox
stNavHitbox = Fill Color 250,0,0,0 | StrokeWidth 0
AntiAlias=1
DynamicVariables=1

[stNavButton]
X=0r
Y=0r
Shape=Rectangle 0,0,#NavButtonSize#,#NavButtonSize#,#ObjectCornerRadius#,#ObjectCornerRadius# | Extend stNavButton
stNavButton = Fill Color 0,250,0 | StrokeWidth 0
AntiAlias=1
DynamicVariables=1
Hidden=1

[stNavBorder]
X=0r
Y=0r
Shape=Rectangle 0,0,#NavButtonSize#,#NavButtonSize#,#ObjectCornerRadius#,#ObjectCornerRadius# | Extend stNavBorder
Shape2=Rectangle #NavButtonBorderThickness#,#NavButtonBorderThickness#,(#NavButtonSize#-(2*#NavButtonBorderThickness#)),(#NavButtonSize#-(2*#NavButtonBorderThickness#)),#ObjectCornerRadius#,#ObjectCornerRadius#
Shape3=Combine Shape | Exclude Shape2
stNavBorder= Fill Color #colorWindowPageBorder# | StrokeWidth 0
AntiAlias=1
DynamicVariables=1
Hidden=1

[stNavGlyph]
X=(#NavButtonSize#/2)r
Y=(#NavButtonSize#/2)r
FontFace=FluentSystemIcons-Regular
FontSize=#FontSize3#
FontColor=#colorWindowIcons#
StringAlign=CENTERCENTER
AntiAlias=1
DynamicVariables=1

[stNavEffect]
X=([mMoveEffect] - #NavButtonSize#)
Y=0
Shape=Rectangle 0,0,(2*#NavButtonSize#),#NavButtonSize# | Extend stNavEffect
stNavEffect = Fill LinearGradient RevealGradient | StrokeWidth 0
RevealGradient = 180 | #colorNavEffect1# ; 0.0 | #colorNavEffect2# ; 0.49 | #colorNavEffect2# ; 0.51 | #colorNavEffect1# ; 1.0
DynamicVariables=1
AntiAlias=1
Group=grEffectReveal

[stWindowTitle]
X=(#WindowBorderThickness# + #LeftPanelMarginSmall# + #NavButtonSize# + #LeftPanelMarginSmall#)
Y=(#TitleBarHeight#/2)
FontFace=#FontFamily#
FontSize=#FontSize2#
FontColor=#colorWindowFont1#
FontWeight=500
StringAlign=LEFTCENTER
AntiAlias=1
DynamicVariables=1

; ---------------------------------------------
; header elements
; ---------------------------------------------

[stProfileMask]
Shape=Ellipse #ProfilePictureR#,#ProfilePictureR#,#ProfilePictureR# | Fill Color 250,0,0 | StrokeWidth 0
X=#LeftPanelMarginBig#
Y=(#HeaderStack# - #ProfilePictureR#)
AntiAlias=1
DynamicVariables=1

[stProfileName]
X=#ProfileDataOffsetL#R
Y=(#HeaderStack# - #ProfileDataOffsetUD#)
FontFace=#FontFamily#
FontSize=#FontSize3#
FontColor=#colorWindowFont1#
FontWeight=500
StringAlign=LEFTCENTER
AntiAlias=1
DynamicVariables=1

[stProfileInfo]
X=0r
Y=(#HeaderStack# + #ProfileDataOffsetUD#)
FontFace=#FontFamily#
FontSize=#FontSize2#
FontColor=#colorWindowFont1#
FontWeight=400
StringAlign=LEFTCENTER
AntiAlias=1
DynamicVariables=1

[stPageTitleText]
X=(#WindowWidthTotal# - #RightPanelWidth# + #RightPanelMarginSmall#)
Y=#HeaderStack#
FontFace=#FontFamily#
FontSize=#FontSize5#
FontColor=#colorWindowFont1#
FontWeight=500
StringAlign=LEFTCENTER
AntiAlias=1
DynamicVariables=1

; ---------------------------------------------
; left panel elements
; ---------------------------------------------

[stSectionLabel]
X=(#WindowBorderThickness# + #LeftPanelMarginSmall#)
FontFace=#FontFamily#
FontSize=#FontSize2#
FontColor=#colorWindowFont2#
FontWeight=400
StringAlign=LEFTCENTER
AntiAlias=1
DynamicVariables=1

[stPageHitbox]
X=(#WindowBorderThickness# + #LeftPanelMarginSmall#)
Y=#PageButtonOffsetB#R
Shape=Rectangle 0,0,#PageButtonWidth#,#PageButtonHeight#,#ObjectCornerRadius#,#ObjectCornerRadius# | Extend stPageHitbox
stPageHitbox = Fill Color 250,0,0,0 | StrokeWidth 0
AntiAlias=1
DynamicVariables=1

[stPageButton]
X=0r
Y=0r
Shape=Rectangle 0,0,#PageButtonWidth#,#PageButtonHeight#,#ObjectCornerRadius#,#ObjectCornerRadius# | Extend stPageButton
stPageButton = Fill Color 0,250,0 | StrokeWidth 0
AntiAlias=1
DynamicVariables=1
Hidden=1

[stPageBorder]
X=0r
Y=0r
Shape=Rectangle 0,0,#PageButtonWidth#,#PageButtonHeight#,#ObjectCornerRadius#,#ObjectCornerRadius# | Extend stPageBorder
Shape2=Rectangle #PageButtonBorderThickness#,#PageButtonBorderThickness#,(#PageButtonWidth#-(2*#PageButtonBorderThickness#)),(#PageButtonHeight#-(2*#PageButtonBorderThickness#)),#ObjectCornerRadius#,#ObjectCornerRadius#
Shape3=Combine Shape | Exclude Shape2
stPageBorder = Fill Color #colorWindowPageBorder# | StrokeWidth 0
DynamicVariables=1
Hidden=1

[stPageEffect]
X=([mMoveEffect] - #PageButtonWidth#)
Y=0
Shape=Rectangle 0,0,(2*#PageButtonWidth#),#PageButtonHeight# | Extend stPageEffect
stPageEffect = Fill LinearGradient RevealGradient | StrokeWidth 0
RevealGradient = 180 | #colorPageEffect1# ; 0.0 | #colorPageEffect2# ; 0.49 | #colorPageEffect2# ; 0.51 | #colorPageEffect1# ; 1.0
DynamicVariables=1
AntiAlias=1
Group=grEffectReveal

[stPageIndicator]
X=0r
Y=0r
Shape=Rectangle 0,((#PageButtonHeight#-#PageIndicatorHeight#)/2),#PageIndicatorWidth#,#PageIndicatorHeight#,#PageIndicatorRadius#,#PageIndicatorRadius# | Extend stPageIndicator
stPageIndicator = Fill Color #colorAccent# | StrokeWidth 0
AntiAlias=1
DynamicVariables=1
Hidden=1

[stPageIcon]
X=(#WindowBorderThickness# + #LeftPanelMarginSmall# + #PageIconOffsetL#)
Y=((#PageButtonHeight#-#PageIconSize#)/2)r
W=#PageIconSize#
H=#PageIconSize#
AntiAlias=1
DynamicVariables=1

[stPageLabel]
X=(#WindowBorderThickness# + #LeftPanelMarginSmall# + #PageIconOffsetL# + #PageIconSize# + #PageLabelOffsetL#)
Y=(#PageIconSize#/2)r
FontFace=#FontFamily#
FontSize=#FontSize2#
FontColor=#colorWindowFont1#
FontWeight=400
StringAlign=LEFTCENTER
AntiAlias=1
DynamicVariables=1



















; ---------------------------------------------
; misc glyphs and icons
; ---------------------------------------------



[stPageTitleGlyph]
X=#PageTitleGlyphOffsetLR#R
Y=#HeaderStack#
FontFace=FluentSystemIcons-Regular
FontSize=#FontSize3#
FontColor=#colorWindowFont2#
StringAlign=CENTERCENTER
FontWeight=700
Text=[\xf2b1]
AntiAlias=1
DynamicVariables=1