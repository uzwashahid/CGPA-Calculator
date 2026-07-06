//#include "Theme.h"
//
//// =====================================================
//// OLIVE GREEN THEME
//// =====================================================
//
//// Background & panels
//const sf::Color Theme::BackgroundColor = sf::Color(247, 248, 242);  // #F7F8F2 - soft off-white
//const sf::Color Theme::PanelColor = sf::Color::White;          // cards
//
//// Primary accent (olive) — drives header, section titles, icons
//const sf::Color Theme::PrimaryColor = sf::Color(85, 107, 47);    // #556B2F - dark olive (Main)
//const sf::Color Theme::SecondaryColor = sf::Color(139, 195, 74);   // #8BC34A - hover (bright olive-lime)
//
//// Text
//const sf::Color Theme::TextColor = sf::Color(34, 34, 34);     // #222222
//const sf::Color Theme::WhiteColor = sf::Color::White;
//const sf::Color Theme::BorderColor = sf::Color(226, 229, 214);  // soft olive-gray outline
//
//// Status colors
//const sf::Color Theme::SuccessColor = sf::Color(85, 107, 47);    // matches Primary olive
//const sf::Color Theme::DangerColor = sf::Color(196, 74, 58);    // muted brick-red for Delete Last
//
//// Muted text (field labels)
//const sf::Color Theme::MutedTextColor = sf::Color(130, 135, 110); // muted olive-gray
//
//// Table
//const sf::Color Theme::TableHeaderColor = sf::Color(107, 142, 35);  // #6B8E23 - button olive (Buttons)
//const sf::Color Theme::RowAltColor = sf::Color(242, 244, 235); // faint olive-gray stripe
//
//// Result cards
//const sf::Color Theme::SemesterCardBg = sf::Color(236, 241, 224); // soft olive-green card
//const sf::Color Theme::SemesterCardBorder = sf::Color(210, 220, 190);
//
//const sf::Color Theme::OverallCardBg = sf::Color(247, 248, 242); // matches background
//const sf::Color Theme::OverallCardBorder = sf::Color(226, 229, 214);
//
//// Footer buttons
//const sf::Color Theme::ExitColor = sf::Color(66, 71, 51);    // dark olive-slate
//const sf::Color Theme::ExitHoverColor = sf::Color(45, 49, 35);
//const sf::Color Theme::DangerHoverColor = sf::Color(168, 58, 45);
//
//const sf::Color Theme::AccentGoldColor = sf::Color(158, 118, 39);


#include "Theme.h"

// =====================================================
// CHARCOAL + ORANGE ACCENT THEME
// =====================================================

// Background & panels
const sf::Color Theme::BackgroundColor = sf::Color(245, 245, 245);  // #F5F5F5 - light gray
const sf::Color Theme::PanelColor = sf::Color(66, 66, 66);     // #424242 - charcoal panels

const sf::Color Theme::PrimaryColor = sf::Color(180, 110, 65);   // dusty terracotta
const sf::Color Theme::SecondaryColor = sf::Color(196, 132, 88);   // hover
//const sf::Color Theme::PrimaryColor = sf::Color(198, 122, 58);   // muted burnt orange (was 255,152,0)
//const sf::Color Theme::SecondaryColor = sf::Color(214, 148, 92);   // softer hover shade (was 255,183,77)

// Text
const sf::Color Theme::TextColor = sf::Color::White;          // white text on dark panels (table rows)
const sf::Color Theme::WhiteColor = sf::Color::White;
const sf::Color Theme::BorderColor = sf::Color(90, 90, 90);     // subtle lighter-charcoal outline

// Status colors
const sf::Color Theme::SuccessColor = sf::Color(129, 199, 132);  // soft green (readable on dark)
const sf::Color Theme::DangerColor = sf::Color(239, 83, 80);    // soft red for Delete Last

// Muted text (field labels) — light gray, since it sits on dark panels now
const sf::Color Theme::MutedTextColor = sf::Color(189, 189, 189);

// Table
const sf::Color Theme::TableHeaderColor = sf::Color(180, 110, 65);
//const sf::Color Theme::TableHeaderColor = sf::Color(198, 122, 58);
const sf::Color Theme::RowAltColor = sf::Color(75, 75, 75);    // slightly lighter charcoal stripe

// Result cards
const sf::Color Theme::SemesterCardBg = sf::Color(58, 74, 60);    // dark muted green-charcoal
const sf::Color Theme::SemesterCardBorder = sf::Color(90, 110, 92);

const sf::Color Theme::OverallCardBg = sf::Color(66, 66, 66);    // matches panel charcoal
const sf::Color Theme::OverallCardBorder = sf::Color(90, 90, 90);

// Footer buttons
const sf::Color Theme::ExitColor = sf::Color(97, 97, 97);    // medium gray
const sf::Color Theme::ExitHoverColor = sf::Color(117, 117, 117);
const sf::Color Theme::DangerHoverColor = sf::Color(198, 40, 40);
