MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro:
	.string "Tui thích mấy cái ma mị…\n"
	.string "Giống như căn bệnh vậy…\p"
	.string "Khi tui đứng đây…\n"
	.string "tui run lên vì nỗi sợ…$"

MtPyre_4F_Text_TashaDefeat:
	.string "Thua rồi, ghét ghê…$"

MtPyre_4F_Text_TashaPostBattle:
	.string "Tui muốn nhìn thấy thứ đó…\n"
	.string "Tui không muốn đi…\p"
	.string "Ở lại…\n"
	.string "Ở lại với tui đi mà?$"

