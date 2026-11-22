AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Hả? Cái gì? Nhà ngươi tính\n"
	.string "làm gì với ĐỘI AQUA?\p"
	.string "ÔNG TRÙM không có ở đây! Ổng đang\n"
	.string "đi lấy cái gì đó quan trọng lắm!\p"
	.string "… …\n"
	.string "Ổng đi đâu hả?\p"
	.string "Wahaha! Ngươi thiệt sự nghĩ\n"
	.string "ta sẽ mở miệng nói ra hả?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Hả? Gì?\n"
	.string "Ngươi là lính ĐỘI MAGMA hả?\p"
	.string "Nghe nói tụi MAGMA đang tính\n"
	.string "đánh thức con POKéMON dữ dữ\l"
	.string "ở CĂN CỨ tụi nó.\p"
	.string "Mà CĂN CỨ tụi nó ở đâu ta?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Cái gì? Cái gì hả? Nhà ngươi tính\n"
	.string "làm gì với ĐỘI AQUA?\p"
	.string "ÔNG TRÙM không có ở đây!\n"
	.string "Ổng đi lên tàu ngầm rồi!\p"
	.string "… …\n"
	.string "Ổng đi đâu hả?\p"
	.string "Wahaha! Ngươi thiệt sự nghĩ\n"
	.string "ta sẽ mở miệng nói ra hả?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Hả? Sao? Nhà ngươi tính\n"
	.string "làm gì với ĐỘI AQUA?\p"
	.string "ÔNG TRÙM không có ở đây! Ổng lại\n"
	.string "chỗ NÚI TIỄN ĐƯA trên ĐƯỜNG 122 rồi!\p"
	.string "… …\n"
	.string "Ổng lại đó làm chi hả?\p"
	.string "Wahaha! Ngươi thiệt sự nghĩ\n"
	.string "ta sẽ mở miệng nói ra hả?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Gì? Gì?\n"
	.string "Ngươi là lính của MAGMA hả?\p"
	.string "Nghe nói tụi MAGMA tính làm gì\n"
	.string "với con POKéMON ở NÚI LỬA á.\p"
	.string "Mà POKéMON nhìn ra sao ta?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Cái gì? Cái gì nữa? Nhà ngươi\n"
	.string "muốn gì với ĐỘI AQUA?\p"
	.string "ÔNG TRÙM không có ở đây!\n"
	.string "Ổng đi qua TP.CẢNG rồi!\p"
	.string "… …\n"
	.string "Lại đó chi hả?\p"
	.string "Wahaha! Ngươi thiệt sự nghĩ\n"
	.string "ta sẽ mở miệng nói ra hả?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Ayiyiyi!\n"
	.string "Phát hiện ra kẻ tình nghi!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Gừưưưư…\n"
	.string "Thua rồi!$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "Ta đã làm nhục ĐỘI mình, dù sao\n"
	.string "thì cũng làm được việc rồi còn gì…$"

