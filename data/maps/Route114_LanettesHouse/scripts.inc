Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_LANETTES_HOUSE
	end

Route114_LanettesHouse_EventScript_Lanette::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_LANETTE, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_LANETTE
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_LANETTE
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "MỸ LAN: Ủa! {PLAYER}!\p"
	.string "Hơi bừa xíu, thông cảm nha…\n"
    .string "Khi mà tui mải mê nghiên cứu,\l"
    .string "thì lại thành ra như vầy…\p"
    .string "Ngại quá… Làm ơn nhận lấy cái này\n"
    .string "để giữ bí mật chuyện này nha.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Bạn có muốn tui chỉ bạn về \n"
    .string "Hệ Thống Lưu Trữ POKéMON không?\p"
    .string "Bạn nên xếp lại BOXES sao cho\n"
    .string "dễ biết được POKéMON nào đang ở trong đó.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Sổ ghi chép nghiên cứu của MỸ LAN.\n"
	.string "Trong này có thông tin về BOXES.\p"
	.string "Thiết kế mỗi BOXES để lưu được 30 POKéMON.\p"
	.string "Mỗi NHL có thể lưu trữ được\n"
	.string "420 POKéMON trong MÁY.\p"
	.string "Đọc tiếp?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Chức năng đánh dấu được thêm để\n"
	.string "phân loại POKéMON hơn.\p"
	.string "Tên và hình nền của mỗi\n"
	.string "BOX có thể đổi khác được\l"
	.string "để nhìn cho đẹp.\p"
	.string "Đọc tiếp?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Khi lưu POKéMON, thì nó sẽ tự động\n"
	.string "chuyển vô BOX mà bạn đã xài hồi nãy.\p"
	.string "Nếu BOX đó đầy, nó sẽ\n"
	.string "chuyển vô BOX kế.\p"
	.string "Tức là, đang xài BOX nào,\n"
	.string "thì nó sẽ tự động chuyển\l"
	.string "POKéMON vô BOX đó.$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} đóng sổ lại.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Có e-mail của ai đó\n"
	.string "gởi tới trong MÁY.\p"
	.string "“… … … … … … …\p"
	.string "“Hệ Thống Lưu Trữ của bạn\n"
    .string "lợi hại hơn của tui.\p"
    .string "“Có nhiều tính năng thân thiện với người\n"
    .string "dùng làm cho nó vừa thú vị vừa hữu ích.\p"
	.string "“Tui rất tự hào vì đã góp phần\n"
    .string "vào quá trình phát triển.\p"
    .string "“Hy vọng bạn sẽ tiếp tục\n"
    .string "nghiên cứu về Hệ Thống Lưu Trữ.\p"
	.string "“BIN\n"
	.string "… … … … … … … …”$"

