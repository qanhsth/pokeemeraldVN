RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Trên bảng có để mấy cái hiệu\n"
	.string "ứng xấu làm ảnh hưởng POKéMON.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Bạn muốn đọc chủ đề nào?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Nếu POKéMON bị hạ độc, nó\n"
	.string "sẽ mất MÁU liên tục.\p"
	.string "Hiệu ứng vẫn sẽ còn\n"
	.string "sau trận đấu.\p"
	.string "POKéMON bị hạ độc sẽ mất\n"
	.string "MÁU khi di chuyển.\p"
	.string "Để chữa trị, hãy xài GIẢI ĐỘC.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Nếu POKéMON bị tê liệt,\n"
	.string "TỐC ĐỘ của nó sẽ bị giảm.\p"
	.string "Nó cũng có thể không\n"
	.string "cử động được luôn.\p"
	.string "Hiệu ứng vẫn sẽ còn sau trận đấu.\n"
	.string "Để chữa trị, hãy xài TRỊ TÊ.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Nếu POKéMON nằm ngủ,\n"
	.string "nó sẽ không tấn công được.\p"
	.string "POKéMON có thể tự thức dậy được,\n"
	.string "mà nếu hết trận, nó vẫn còn ngủ\l"
	.string "thì nó vẫn sẽ tiếp tục ngủ.\p"
	.string "Để chữa trị, hãy xài ĐÁNH THỨC.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Nếu POKéMON bị phỏng, nó sẽ\n"
	.string "bị giảm ST và bị mất MÁU liên tục.\p"
	.string "Hiệu ứng vẫn sẽ còn sau trận đấu.\n"
	.string "Để chữa trị, hãy xài TRỊ PHỎNG.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Nếu POKéMON bị đóng băng, nó\n"
	.string "sẽ không làm gì được hết.\p"
	.string "Hiệu ứng vẫn sẽ còn sau trận đấu.\n"
	.string "Để chữa trị, hãy xài TAN BĂNG.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Những ai mà không chịu học\n"
	.string "sẽ phải nếm mùi MÓNG TRƯỚC của ta.\p"
	.string "Dù con có học giỏi hay không\n"
	.string "thì thông qua cách xài vật phẩm\l"
	.string "này sẽ chứng minh được thôi.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Cho POKéMON cầm MÓNG TRƯỚC\n"
	.string "thi thoảng nó sẽ tăng tốc\l"
	.string "và hành động nhanh hơn đối thủ.\p"
	.string "Có rất là nhiều vật phẩm\n"
	.string "mà POKéMON có thể cầm được.\p"
	.string "Chỉ nhiêu đó thôi mà cũng có\n"
	.string "nhiều đề tài để nghiên cứu rồi!$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "Tui đang trao đổi POKéMON\n"
	.string "với bạn tui nè.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "Tui muốn có SEEDOT quá,\n"
	.string "và cuối cùng cũng có được rồi!$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "POKéMON có thể cầm vật phẩm, nhưng\n"
	.string "tụi nó không có biết xài mấy cái\l"
	.string "như là BÌNH MÁU với GIẢI ĐỘC đâu.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Bạn có biết mấy chiêu\n"
	.string "làm chóng mặt POKéMON không?\p"
	.string "POKéMON bị chóng mặt, lâu lâu\n"
	.string "nó sẽ tự làm thương mình.\p"
	.string "Nhưng khi hết trận, nó\n"
	.string "sẽ trở lại như thường thôi.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "POKéMON mà cầm TRÁI CÂY\n"
	.string "thì nó tự hồi phục cho nó luôn…\p"
	.string "Có rất nhiều loại vật phẩm\n"
	.string "mà POKéMON có thể cầm được…\p"
	.string "Mà nhiều lắm, không\n"
	.string "có nhớ nổi đâu…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "Đây là cuốn vở của học sinh…\p"
	.string "POKéMON có thể được bắt bằng\n"
	.string "QUẢ CẦU POKéMON.\p"
	.string "NHL có thể đem theo\n"
	.string "tới 6 POKéMON.\p"
	.string "NHL là người bắt POKéMON,\n"
	.string "nuôi nó, rồi thách đấu\l"
	.string "cùng với nó.\p"
	.string "Nhiệm vụ của NHL là\n"
	.string "đánh bại NHL mạnh hơn\l"
	.string "đang chờ ở NHÀ THI ĐẤU.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Ủa? Hình như có gặp 1 lần rồi thì phải.\n"
	.string "Hồi ở TP.HOA CAM á.\p"
	.string "Để chú giới thiệu lại nha.\n"
	.string "Chú tên là SƠN.\p"
	.string "Chú đang đi khắp nơi, để\n"
	.string "tìm kiếm NHL tài năng.\p"
	.string "Đặc biệt là, mấy người có\n"
	.string "kinh nghiệm thách đấu POKéMON.\p"
	.string "Mà sao con lại tới trường này?\n"
	.string "Con cũng là NHL phải không?\p"
	.string "Rồi bây giờ con cho POKéMON\n"
	.string "học chiêu CẮT trước đi.\p"
	.string "Nếu chú nhớ không lầm, trong thị\n"
	.string "trấn này có người sở hữu CẮT đó.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SƠN: Hừmm…\p"
	.string "Tài năng của học sinh ở đây\n"
	.string "chưa được rõ lắm. Nhưng có tiềm năng.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SƠN: Trời, cái đó là gì vậy?\p"
	.string "HUY HIỆU ĐÁ phải không?\n"
	.string "Phải nói rất là ấn tượng.\p"
	.string "Nhưng mà chú cũng muốn\n"
	.string "thấy con thách đấu á.\p"
	.string "Cũng khó để biết con là NHL mạnh\n"
	.string "cỡ nào khi chỉ nhìn HUY HIỆU.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Ủa? Hình như có gặp 1 lần rồi thì phải.\n"
	.string "Hồi ở TP.HOA CAM á.\p"
	.string "Để chú giới thiệu lại nha.\n"
	.string "Chú tên là SƠN.\p"
	.string "Chú đang đi khắp nơi, để\n"
	.string "tìm kiếm NHL tài năng.\p"
	.string "Đặc biệt là, mấy người có\n"
	.string "kinh nghiệm thách đấu POKéMON.\p"
	.string "Trời, cái đó là gì vậy?\n"
	.string "HUY HIỆU ĐÁ phải không?\p"
	.string "Phải nói rất là ấn tượng cho\n"
	.string "một người mới bắt đầu như con.\p"
	.string "Nhưng mà chú cũng muốn\n"
	.string "thấy con thách đấu á.\p"
	.string "Cũng khó để biết con là NHL\n"
	.string "sao khi chỉ nhìn HUY HIỆU.$"
