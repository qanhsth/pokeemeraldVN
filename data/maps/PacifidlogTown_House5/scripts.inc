PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Nay hết thấy ĐẢO ẢO ẢNH rồi…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Ủa! Trời ơi!\n"
	.string "Nay thấy được ĐẢO ẢO ẢNH rồi nè!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "ĐẢO ẢO ẢNH…\p"
	.string "Chắc nó thoắt ẩn, thoắt hiện\n"
	.string "tuỳ theo tình hình thời tiết\l"
	.string "mà cái ảo ảnh xuất hiện.\p"
	.string "Hay là tại nó tự biến mất\n"
	.string "rồi hiện ra lại?$"

