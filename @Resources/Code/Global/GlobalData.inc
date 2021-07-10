; ------------------------------------------------
; variables used in all skins in the suite
; ------------------------------------------------

[Variables]
@includeAccent=#@#Code/Global/ColorsAccent.inc

; ------------------------------------------------
; general interface settings
; ------------------------------------------------

; user scale
valueUserScale = 1.0

; blur used for all translucent panels
valueBlurType=Blur

; corner radius values
WindowCornerRadius=(10 * #valueUserScale#)
ObjectCornerRadius=(5 * #valueUserScale#)

; font type and size
FontFamily = Segoe UI
FontSize1 = (8 * #valueUserScale#)
FontSize2 = (10 * #valueUserScale#)
FontSize3 = (12 * #valueUserScale#)
FontSize4 = (14 * #valueUserScale#)
FontSize5 = (20 * #valueUserScale#)

; color scheme
WindowsColorScheme=Light
TaskbarColorScheme=Light

; opacity values
valueWindowOpacity = 230
valueTaskbarOpacity = 230

; ---------------------------------------------
; blur measure for all skins
; ---------------------------------------------

[mBackgroundBlur]
Measure=Plugin
Plugin=FrostedGlass
Type=#valueBlurType#
Border=None

