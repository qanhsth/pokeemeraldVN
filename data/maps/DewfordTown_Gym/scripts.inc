DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Ê, dạo này sao rồi, ứng cử viên VÔ ĐỊCH\n"
	.string "{PLAYER}?\p"
	.string "ĐÔNG, CHỦ GYM THÔN ĐẢO, chỉ chơi\n"
	.string "POKéMON hệ VÕ SĨ thôi.\p"
	.string "Xài POKéMON hệ THƯỜNG\n"
	.string "là thua đó nha.\p"
	.string "POKéMON hệ VÕ SĨ đánh 1 đòn\n"
	.string "rất đau vô POKéMON hệ THƯỜNG,\l"
	.string "nên là hãy cẩn thận!\p"
	.string "Còn tệ hơn nữa là cái NHÀ THI ĐẤU\n"
	.string "tối thui như đáy biển vậy.\p"
	.string "Nhưng mà nó sẽ sáng lên nếu như bạn\n"
	.string "đánh bại được NHL cản đường mình.\p"
	.string "Mà thôi cứ đánh hết mình đi!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Trời! Tự nhiên trong đây sáng quá!\p"
	.string "Tương lai của bạn cũng sáng nữa!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "Sức mạnh là chân lý!\n"
	.string "Nhào vô!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Không đủ công lực rồi…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Kỹ năng của bạn và\n"
	.string "kỹ thuật của bạn là quá dữ!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Không cần ĐÔNG phải\n"
	.string "nhúng tay vô!\p"
	.string "Tui sẽ nghiền nát bạn tại đây!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Sao… có thể như vậy?\n"
	.string "Sao mà thua dễ quá vậy?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Tui sẽ tận dụng cái thua này.\n"
	.string "Để làm động lực phấn đấu!\p"
	.string "Rồi sẽ có ngày tui thành CHỦ GYM…\p"
	.string "Không, tui sẽ thành NHÀ VÔ ĐỊCH\n"
	.string "LIÊN ĐOÀN POKéMON!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Đừng có khi dễ tui!\n"
	.string "Thua đừng có khóc nghe chưa!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Waaaaaaah!\n"
	.string "Thua rồi!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Chiến đấu trong bóng tối làm\n"
	.string "cho tinh thần mạnh hơn.\p"
	.string "Nhưng mà tối quá, tui còn không\n"
	.string "thấy mặt ĐÔNG nữa…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Làm gì ở trong bóng tối vậy?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Trời ơi bạn…\n"
	.string "Tui không muốn thấy bạn nữa đâu!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Bạn chỉ xứng đáng thua rồi\n"
	.string "quay lại cổng thôi!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Tui sẽ cho bạn biết\n"
	.string "sự gan dạ của 1 thuỷ thủ!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Sao có thể như vậy được?\n"
	.string "Người như tui mà thua kiểu này sao!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Ê! Bạn xứng đáng được thách\n"
	.string "đấu với CHỦ GYM tụi tui.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Nếu muốn đi qua,\n"
	.string "thì hãy bước qua tui trước!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Gừưưưư!\n"
	.string "Quá mạnh!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Bạn thắng rồi!\n"
	.string "Hãy giành lấy cái HUY HIỆU đi!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Ta là ĐÔNG!\n"
	.string "CHỦ GYM THÔN ĐẢO!\p"
	.string "Những con sóng dữ dội ở đây\n"
	.string "đánh dạt ta tứ tung, và rồi ta đã\l"
	.string "cứng cỏi hơn trong cái hang tối thui!\p"
	.string "Nhà ngươi muốn thách đấu ta sao?\n"
	.string "Để coi ngươi làm được gì!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Whoah, wow! Không ngờ ngươi\n"
	.string "tạo được vệt nước quá lớn!\p"
	.string "Nhấn chìm POKéMON của ta rồi!\p"
	.string "Thôi ta nhận thua.\n"
	.string "Cầm lấy HUY HIỆU đi!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} nhận HUY HIỆU NẮM ĐẤM\n"
	.string "từ ĐÔNG.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "HUY HIỆU NẮM ĐẤM làm cho POKéMON\n"
	.string "nghe lời cho tới cấp 30,\l"
	.string "kể cả là POKéMON trao đổi đi nữa.\p"
	.string "Nhà ngươi được phép xài chiêu HM\n"
	.string "CHÓI ngoài ván đấu.\p"
	.string "Nếu thích, thì lấy cái\n"
	.string "MÁY HỌC CHIÊU này luôn đi.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "TM08 có chứa GỒNG CƠ.\p"
	.string "Là chiêu thức vừa tăng ST\n"
	.string "vừa tăng GIÁP luôn.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "Lưu số ĐÔNG CHỦ GYM\n"
	.string "vô BẢN ĐỒ.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Ta có thể thấy tài năng của ngươi\n"
	.string "sẽ trở thành làn sóng bão bùng\l"
	.string "trong giới NHL 1 ngày nào đó!$"

DewfordTown_Gym_Text_GymStatue:
	.string "NHÀ THI ĐẤU THÔN ĐẢO"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "NHÀ THI ĐẤU THÔN ĐẢO\p"
	.string "ĐÔNG CÔNG NHẬN NHL:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "ĐÔNG: Sóng có thể rút lại,\n"
	.string "nhưng sẽ luôn quay lại bờ.\p"
	.string "Một người tài năng như ngươi…\n"
	.string "Ta biết là sẽ quay lại!\p"
	.string "Hãy cho ta thấy trình độ\n"
	.string "của ngươi lên tới đâu rồi!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Wow!\n"
	.string "Bị nhấn chìm nữa rồi!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "ĐÔNG: Thách đấu rất sâu và rộng.\n"
	.string "Ngươi không thấy được đáy đâu.\l"
	.string "Giống như biển ở HOENN vậy!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "ĐÔNG: Sóng có thể rút lại,\n"
	.string "nhưng sẽ luôn quay lại bờ.\p"
	.string "Một người tài năng như ngươi…\n"
	.string "Ta biết là sẽ quay lại!\p"
	.string "Ủa? Ngươi chỉ có 1 POKéMON\n"
	.string "để thách đấu thôi sao.\p"
	.string "Ta xin lỗi nhưng hãy\n"
	.string "quay lại với ít nhất 2 POKéMON.$"
