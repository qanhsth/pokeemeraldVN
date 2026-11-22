MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Kỷ niệm với SKITTY của tui…\n"
	.string "Mắt tui không còn kiềm được nữa.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ây, ây da… Có cái lỗ trên\n"
	.string "mặt đất ở đây với chỗ kia.\p"
	.string "Tui không để ý, làm trượt\n"
	.string "chưn té từ trên xuống.$"

MtPyre_2F_Text_MarkIntro:
	.string "Ê! Kiếm POKéMON hả?\n"
	.string "Sao lại đi sau lưng ta! Mất nết!$"

MtPyre_2F_Text_MarkDefeat:
	.string "Ayieeeeh!\n"
	.string "Xin lỗi, xin lỗi nha!$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Người ta ít tới đây lắm, nên là\n"
	.string "tui tưởng sẽ có POKéMON hiếm.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUÂN: Tụi tui tới đây để thử thách.\p"
    .string "Heheh, nếu mà tui cho cổ thấy mình ngầu,\n"
    .string "cổ sẽ phải lòng tui. Tui biết rồi!\p"
    .string "Biết rồi! Tui sẽ đánh bại bạn để\n"
    .string "lấy le với cổ!$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUÂN: Ủaaaa!$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUÂN: Ừa, thì thua, mà kệ đi!\n"
	.string "Anh vẫn ở đây với em.\l"
	.string "Tụi mình cùng nhau vượt qua thử thách!$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUÂN: Nếu muốn chơi,\n"
	.string "thì đem thêm POKéMON đi.\p"
	.string "Nếu không, thì tui không còn cơ hội\n"
	.string "để thể hiện với bạn gái nữa!$"

MtPyre_2F_Text_DezIntro:
	.string "DUNG: Tui lại đây với bạn trai\n"
	.string "để thử thách.\p"
	.string "Thiệt tình là sợ lắm, mà nghĩ lại mình\n"
	.string "đi chung với bạn trai. Nên hổng sao.\p"
	.string "Biết rồi! Tui sẽ làm cho bạn trai mình\n"
	.string "ngầu lên để hạ gục bạn!$"

MtPyre_2F_Text_DezDefeat:
	.string "DUNG: Waaaah! Sợ quáaa!$"

MtPyre_2F_Text_DezPostBattle:
	.string "DUNG: Tụi tui yêu nhau thắm thiết\n"
	.string "lắm, nên là có thua thì cũng kệ!$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DUNG: Nếu muốn thách đấu, bạn\n"
	.string "phải đem ít nhất 2 POKéMON.\p"
	.string "Bạn trai tui mạnh lắm đó.\n"
	.string "Một con POKéMON thôi hong ăn thua đâu.$"

MtPyre_2F_Text_LeahIntro:
    .string "Nhà ngươi nhìn lạ quá…\n"
    .string "Biến khỏi đây trước khi có chuyện!$"

MtPyre_2F_Text_LeahDefeat:
    .string "Hừm…\n"
    .string "Ngươi thật là cứng rắn.$"

MtPyre_2F_Text_LeahPostBattle:
    .string "Gia đình ta là NHL ở đây\n"
    .string "từ thời bà cố rồi…\p"
    .string "Nhiệm vụ của ta là bảo vệ\n"
    .string "ngọn núi này…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kiyaaaaah!\n"
	.string "Ghê chưa!$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Trờiiiiiii!\n"
	.string "Hết cười nỗi!$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Mỗi lần thấy cái gì đó nhúc nhích\n"
	.string "là tui hú vía…\p"
	.string "Đáng lẽ tui không nên tới đây…$"

