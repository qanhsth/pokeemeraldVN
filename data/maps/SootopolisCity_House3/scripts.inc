SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Bạn là NHL POKéMON, phải không?\p"
	.string "Ông CHUẨN ở LƯU NIẾT có rất nhiều fan.\n"
	.string "Còn nhiều hơn học trò ổng, HẢI LY luôn!\p"
	.string "Bạn có fan không?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Ồ, vậy chắc bạn cũng mạnh lắm.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Ủa, vậy hả…\n"
	.string "Hơi buồn một xíu.\p"
	.string "Cố gắng hơn xíu nữa để\n"
	.string "có fan theo ủng hộ.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Mấy người fan cuồng từ ở\n"
	.string "bên ngoài HOENN tới đây.\p"
	.string "CLB HÂM MỘ ở TP.BIỂN\n"
	.string "rất là náo nhiệt.$"

