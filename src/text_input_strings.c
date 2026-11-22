#include "global.h"

// Easy Chat keyboard
const u8 gText_EasyChatKeyboard_ABCDEFothers[] = _("{CLEAR 11}A{CLEAR 6}B{CLEAR 6}C{CLEAR 26}D{CLEAR 6}E{CLEAR 6}F{CLEAR 26}others");
const u8 gText_EasyChatKeyboard_GHIJKL[] = _("{CLEAR 11}G{CLEAR 6}H{CLEAR 6}I{CLEAR 26}J{CLEAR 6}K{CLEAR 6}L");
const u8 gText_EasyChatKeyboard_MNOPQRS[] = _("{CLEAR 11}M{CLEAR 6}N{CLEAR 6}O{CLEAR 26}P{CLEAR 6}Q{CLEAR 6}R{CLEAR 6}S{CLEAR 26} ");
const u8 gText_EasyChatKeyboard_TUVWXYZ[] = _("{CLEAR 11}T{CLEAR 6}U{CLEAR 6}V{CLEAR 26}W{CLEAR 6}X{CLEAR 6}Y{CLEAR 6}Z{CLEAR 26} ");

// Naming Screen keyboard
const u8 gText_NamingScreenKeyboard_abcdef[] = _("{CLEAR 11}a{CLEAR 6}b{CLEAR 6}c{CLEAR 26}d{CLEAR 6}e{CLEAR 6}f{CLEAR 6} {CLEAR 30}.");
const u8 gText_NamingScreenKeyboard_ghijkl[] = _("{CLEAR 11}g{CLEAR 6}h{CLEAR 7}i{CLEAR 27}j{CLEAR 7}k{CLEAR 7}l{CLEAR 7} {CLEAR 30},");
const u8 gText_NamingScreenKeyboard_mnopqrs[] = _("{CLEAR 11}m{CLEAR 6}n{CLEAR 6}o{CLEAR 26}p{CLEAR 6}q{CLEAR 7}r{CLEAR 6}s{CLEAR 27} ");
const u8 gText_NamingScreenKeyboard_tuvwxyz[] = _("{CLEAR 11}t{CLEAR 6}u{CLEAR 6}v{CLEAR 26}w{CLEAR 6}x{CLEAR 6}y{CLEAR 6}z{CLEAR 26} ");
const u8 gText_NamingScreenKeyboard_vn1_line1[] = _("{CLEAR 11}á{CLEAR 6}à{CLEAR 6}ả{CLEAR 26}ã{CLEAR 6}ạ{CLEAR 6}ă{CLEAR 6}ắ{CLEAR 22}ằ{CLEAR 6}ẳ");
const u8 gText_NamingScreenKeyboard_vn1_line2[] = _("{CLEAR 11}ẵ{CLEAR 6}ặ{CLEAR 6}â{CLEAR 26}ấ{CLEAR 6}ầ{CLEAR 6}ẩ{CLEAR 6}ẫ{CLEAR 22}ậ{CLEAR 6}đ");
const u8 gText_NamingScreenKeyboard_vn1_line3[] = _("{CLEAR 11}é{CLEAR 6}è{CLEAR 6}ẻ{CLEAR 26}ẽ{CLEAR 6}ẹ{CLEAR 6}ê{CLEAR 6}ế{CLEAR 22}ề");
const u8 gText_NamingScreenKeyboard_vn1_line4[] = _("{CLEAR 11}ể{CLEAR 6}ễ{CLEAR 6}ệ{CLEAR 26}í{CLEAR 6}ì{CLEAR 6}ỉ{CLEAR 6}ĩ{CLEAR 23}ị"); 
const u8 gText_NamingScreenKeyboard_vn2_line1[] = _("{CLEAR 11}ó{CLEAR 6}ò{CLEAR 6}ỏ{CLEAR 26}õ{CLEAR 6}ọ{CLEAR 6}ô{CLEAR 6}ố{CLEAR 22}ồ");
const u8 gText_NamingScreenKeyboard_vn2_line2[] = _("{CLEAR 11}ổ{CLEAR 6}ỗ{CLEAR 6}ộ{CLEAR 26}ơ{CLEAR 6}ớ{CLEAR 6}ờ{CLEAR 6}ở{CLEAR 22}ỡ");
const u8 gText_NamingScreenKeyboard_vn2_line3[] = _("{CLEAR 11}ợ{CLEAR 6}ú{CLEAR 6}ù{CLEAR 26}ủ{CLEAR 6}ũ{CLEAR 6}ụ{CLEAR 6}ư{CLEAR 21}ứ");
const u8 gText_NamingScreenKeyboard_vn2_line4[] = _("{CLEAR 11}ừ{CLEAR 5}ử{CLEAR 5}ữ{CLEAR 25}ự{CLEAR 5}ý{CLEAR 6}ỳ{CLEAR 6}ỷ{CLEAR 22}ỹ{CLEAR 6}ỵ");
const u8 gText_NamingScreenKeyboard_ABCDEF[] = _("{CLEAR 11}A{CLEAR 6}B{CLEAR 6}C{CLEAR 26}D{CLEAR 6}E{CLEAR 6}F{CLEAR 6} {CLEAR 30}.");
const u8 gText_NamingScreenKeyboard_GHIJKL[] = _("{CLEAR 11}G{CLEAR 6}H{CLEAR 6}I{CLEAR 26}J{CLEAR 6}K{CLEAR 6}L{CLEAR 6} {CLEAR 30},");
const u8 gText_NamingScreenKeyboard_MNOPQRS[] = _("{CLEAR 11}M{CLEAR 6}N{CLEAR 6}O{CLEAR 26}P{CLEAR 6}Q{CLEAR 6}R{CLEAR 6}S{CLEAR 26} ");
const u8 gText_NamingScreenKeyboard_TUVWXYZ[] = _("{CLEAR 11}T{CLEAR 6}U{CLEAR 6}V{CLEAR 26}W{CLEAR 6}X{CLEAR 6}Y{CLEAR 6}Z{CLEAR 26} ");
const u8 gText_NamingScreenKeyboard_VN1_LINE1[] = _("{CLEAR 11}Á{CLEAR 6}À{CLEAR 6}Ả{CLEAR 26}Ã{CLEAR 6}Ạ{CLEAR 6}Ă{CLEAR 6}Ắ{CLEAR 20}Ằ{CLEAR 4}Ẳ");
const u8 gText_NamingScreenKeyboard_VN1_LINE2[] = _("{CLEAR 11}Ẵ{CLEAR 3}Ặ{CLEAR 6}Â{CLEAR 26}Ấ{CLEAR 4}Ầ{CLEAR 4}Ẩ{CLEAR 4}Ẫ{CLEAR 19}Ậ{CLEAR 4}Đ");
const u8 gText_NamingScreenKeyboard_VN1_LINE3[] = _("{CLEAR 11}É{CLEAR 6}È{CLEAR 6}Ẻ{CLEAR 26}Ẽ{CLEAR 6}Ẹ{CLEAR 6}Ê{CLEAR 6}Ế{CLEAR 20}Ề");
const u8 gText_NamingScreenKeyboard_VN1_LINE4[] = _("{CLEAR 11}Ể{CLEAR 4}Ễ{CLEAR 3}Ệ{CLEAR 26}Í{CLEAR 6}Ì{CLEAR 6}Ỉ{CLEAR 6}Ĩ{CLEAR 22}Ị");
const u8 gText_NamingScreenKeyboard_VN2_LINE1[] = _("{CLEAR 11}Ó{CLEAR 6}Ò{CLEAR 6}Ỏ{CLEAR 26}Õ{CLEAR 6}Ọ{CLEAR 6}Ô{CLEAR 6}Ố{CLEAR 20}Ồ");
const u8 gText_NamingScreenKeyboard_VN2_LINE2[] = _("{CLEAR 11}Ổ{CLEAR 4}Ỗ{CLEAR 3}Ộ{CLEAR 26}Ơ{CLEAR 6}Ớ{CLEAR 6}Ờ{CLEAR 6}Ở{CLEAR 22}Ỡ");
const u8 gText_NamingScreenKeyboard_VN2_LINE3[] = _("{CLEAR 11}Ợ{CLEAR 6}Ú{CLEAR 6}Ù{CLEAR 26}Ủ{CLEAR 6}Ũ{CLEAR 6}Ụ{CLEAR 6}Ư{CLEAR 21}Ứ");
const u8 gText_NamingScreenKeyboard_VN2_LINE4[] = _("{CLEAR 11}Ừ{CLEAR 5}Ử{CLEAR 5}Ữ{CLEAR 25}Ự{CLEAR 5}Ý{CLEAR 6}Ỳ{CLEAR 6}Ỷ{CLEAR 22}Ỹ{CLEAR 6}Ỵ");
const u8 gText_NamingScreenKeyboard_01234[] = _("{CLEAR 11}0{CLEAR 16}1{CLEAR 16}2{CLEAR 16}3{CLEAR 16}4{CLEAR 16} ");
const u8 gText_NamingScreenKeyboard_56789[] = _("{CLEAR 11}5{CLEAR 16}6{CLEAR 16}7{CLEAR 16}8{CLEAR 16}9{CLEAR 16} ");
const u8 gText_NamingScreenKeyboard_Symbols1[] = _("{CLEAR 12}!{CLEAR 17}?{CLEAR 16}♂{CLEAR 16}♀{CLEAR 16}/{CLEAR 17}-");
const u8 gText_NamingScreenKeyboard_Symbols2[] = _("{CLEAR 11}…{CLEAR 16}“{CLEAR 16}”{CLEAR 18}‘{CLEAR 19}'{CLEAR 18} ");

// Union Room Chat keyboard
const u8 gText_UnionRoomChatKeyboard_ABCDE[] = _("ABCDE");
const u8 gText_UnionRoomChatKeyboard_FGHIJ[] = _("FGHIJ");
const u8 gText_UnionRoomChatKeyboard_KLMNO[] = _("KLMNO");
const u8 gText_UnionRoomChatKeyboard_PQRST[] = _("PQRST");
const u8 gText_UnionRoomChatKeyboard_UVWXY[] = _("UVWXY");
const u8 gText_UnionRoomChatKeyboard_Z[] = _("Z    ");
const u8 gText_UnionRoomChatKeyboard_01234Upper[] = _("01234");
const u8 gText_UnionRoomChatKeyboard_56789Upper[] = _("56789");
const u8 gText_UnionRoomChatKeyboard_PunctuationUpper[] = _(".,!? ");
const u8 gText_UnionRoomChatKeyboard_SymbolsUpper[] = _("-/&… ");
const u8 gText_UnionRoomChatKeyboard_abcde[] = _("abcde");
const u8 gText_UnionRoomChatKeyboard_fghij[] = _("fghij");
const u8 gText_UnionRoomChatKeyboard_klmno[] = _("klmno");
const u8 gText_UnionRoomChatKeyboard_pqrst[] = _("pqrst");
const u8 gText_UnionRoomChatKeyboard_uvwxy[] = _("uvwxy");
const u8 gText_UnionRoomChatKeyboard_z[] = _("z    ");
const u8 gText_UnionRoomChatKeyboard_01234Lower[] = _("01234");
const u8 gText_UnionRoomChatKeyboard_56789Lower[] = _("56789");
const u8 gText_UnionRoomChatKeyboard_PunctuationLower[] = _(".,!? ");
const u8 gText_UnionRoomChatKeyboard_SymbolsLower[] = _("-/&… ");

const u8 gText_EmptyTextInput1[] = _("");
const u8 gText_EmptyTextInput2[] = _("");
const u8 gText_EmptyTextInput3[] = _("");
const u8 gText_EmptyTextInput4[] = _("");
const u8 gText_EmptyTextInput5[] = _("");
const u8 gText_EmptyTextInput6[] = _("");
const u8 gText_EmptyTextInput7[] = _("");
const u8 gText_EmptyTextInput8[] = _("");

// Union Room Chat keyboard emojis
const u8 gText_UnionRoomChatKeyboard_Emoji1[] = _("{EMOJI_MISCHIEVOUS}{EMOJI_HAPPY}{EMOJI_ANGRY}{EMOJI_SURPRISED}{EMOJI_BIGANGER}");
const u8 gText_UnionRoomChatKeyboard_Emoji2[] = _("{EMOJI_BIGSMILE}{EMOJI_EVIL}{EMOJI_NEUTRAL}{EMOJI_TIRED}{EMOJI_SHOCKED}");
const u8 gText_UnionRoomChatKeyboard_Emoji3[] = _("{EMOJI_LEAF}{EMOJI_FIRE}{EMOJI_WATER}{EMOJI_BOLT}{EMOJI_BALL}");
const u8 gText_UnionRoomChatKeyboard_Emoji4[] = _("♂♀{EMOJI_LEFT_PAREN}{EMOJI_RIGHT_PAREN}{EMOJI_TILDE}");
const u8 gText_UnionRoomChatKeyboard_Emoji5[] = _("{EMOJI_LEFT_EYE}{EMOJI_RIGHT_EYE}{EMOJI_SMALLWHEEL}{EMOJI_SPHERE}{EMOJI_IRRITATED}");
const u8 gText_UnionRoomChatKeyboard_Emoji6[] = _("{EMOJI_AT}{EMOJI_BIGWHEEL}{EMOJI_TONGUE}{EMOJI_ACUTE}{EMOJI_GRAVE}");
const u8 gText_UnionRoomChatKeyboard_Emoji7[] = _("{EMOJI_RIGHT_FIST}{EMOJI_LEFT_FIST}{EMOJI_TRIANGLE_OUTLINE}{EMOJI_UNION}{EMOJI_GREATER_THAN}");
const u8 gText_UnionRoomChatKeyboard_Emoji8[] = _("{EMOJI_CIRCLE}{EMOJI_TRIANGLE}{EMOJI_SQUARE}{EMOJI_HEART}{EMOJI_MOON}");
const u8 gText_UnionRoomChatKeyboard_Emoji9[] = _("{EMOJI_NOTE}{EMOJI_PLUS}{EMOJI_MINUS}{EMOJI_EQUALS}{EMOJI_PIPE}");
const u8 gText_UnionRoomChatKeyboard_Emoji10[] = _("{EMOJI_HIGHBAR}{EMOJI_UNDERSCORE};: ");
