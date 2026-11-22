LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Ê, khoẻ không, ứng cử viên\n"
	.string "VÔ ĐỊCH {PLAYER}?\p"
	.string "CHỦ GYM NÚI LỬA, HOẢ LY,\n"
	.string "xài POKéMON hệ LỬA.\p"
	.string "Niềm đam mê POKéMON của cổ bùng cháy\n"
    .string "và nóng bỏng hơn cả một ngọn núi lửa.\p"
    .string "Đừng lại gần cổ--phỏng đó!\n"
    .string "Dội nước vô người cổ rồi\l"
    .string "hẳn lao vô!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
    .string "Trời! Một trận đấu đầy nóng bỏng!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Âydaâydaâyda!\n"
	.string "Trời, nóng quá!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Mồ hôi làm mù mắt tui…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Chôn mình trong cát nóng giúp\n"
    .string "tăng cường tuần hoàn máu.\p"
    .string "Nó còn có tác dụng làm dịu\n"
    .string "cơn đau khớp.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Tui đang giải tỏa căng thẳng.\n"
    .string "Đừng có làm tui căng thẳng thêm!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Hy vọng HOẢ LY sẽ thiêu rụi bạn!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Phù…\p"
	.string "Nếu bạn chôn mình trong cát nóng\n"
    .string "quá lâu, bạn sẽ kiệt sức…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Chắc bạn mệt rồi.\n"
	.string "Bạn muốn ngâm mình trong\l"
	.string "cát nóng lắm rồi phải không?\p"
	.string "Mà bạn cũng nên biết giữ\n"
    .string "vững tâm trí là một kỹ năng\l"
    .string "quan trọng đối với các NHL.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Giỡn với lửa, coi chừng phỏng…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Bạn cũng có trình độ đó…\n"
	.string "Mà CHỦ GYM HOẢ LY mạnh lắm.\p"
	.string "Nếu không cẩn thận,\n"
	.string "coi chừng phỏng tay.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "POKéMON của bạn chịu nổi\n"
	.string "392 độ không?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Chưa đủ nóng…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "Nhiệt độ của mắc ma là\n"
	.string "392 độ.\p"
	.string "POKéMON của bạn đã hạ gục tui,\n"
	.string "vậy nên nó có thể sinh tồn trong mắc ma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Mm…\n"
	.string "Được thôi, tui sẽ đấu với bạn.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Mà bạn mạnh quá rồi.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Tui sẽ trở nên xinh đẹp và\n"
	.string "mạnh mẽ giống HOẢ LY.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Lẹ lẹ đi!\n"
	.string "Để thôi lửa nó nguội!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
    .string "Nóng quá trời, mà tim tui\n"
    .string "thì lạnh ngắt…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
    .string "Với ngọn lửa đang bùng cháy\n"
    .string "trong tim, có lẽ bạn sẽ có cơ hội\l"
    .string "đấu lại CHỦ GYM của tụi tui.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
    .string "Thấy lửa cháy dữ dội không?\n"
    .string "Là để chào đón chiến thắng của tui đó!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
    .string "Có gì đó sai sai.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
    .string "Thì sao? Tui nói là vậy thì đã sao?\n"
    .string "Tui đi chưn không lên than nóng luôn nè!\p"
    .string "…Đừng có bắt chước theo nha!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Tui yêu núi,\n"
	.string "kể cả là núi lửa.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
    .string "Chà, có vẻ như tui đã thua mà\n"
    .string "chưa kịp nắm thế chủ động.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
    .string "Tui ở lại đây vì tui hâm mộ\n"
    .string "sức mạnh của HOẢ LY.\p"
    .string "Hehehehe.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Chào mừng… Mà khoan.\p"
	.string "Hỡi NHL yếu ớt kia, rất vui khi\n"
    .string "thấy ngươi đã tới được đây!\p"
    .string "Ta đã được giao phó nhiệm vụ…\n"
    .string "Mà khoan.\p"
    .string "Tui là HOẢ LY, và tui là\n"
    .string "CHỦ GYM ở đây!\p"
	.string "Ừm…\n"
    .string "Mà đừng có khi dễ tui nha.\l"
    .string "Tui mới làm CHỦ GYM gần đây thôi!\p"
    .string "Với kỹ năng thừa hưởng từ ông nội,\n"
    .string "tui sẽ, ừm…phô diễn chiêu thức\l"
    .string "nóng bỏng mà tui đã luyện được!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Ụa…\n"
	.string "Vậy là cố quá thành quá cố rồi…\p"
	.string "Tui… Tui chỉ mới làm\n"
	.string "CHỦ GYM gần đây thôi.\p"
	.string "Tui cố gắng để\n"
	.string "trở nên khác hơn.\p"
	.string "Tui phải để mọi chuyện thuận theo\n"
	.string "tự nhiên. Nếu không, POKéMON sẽ bị bối\p"
	.string "rối. Cảm ơn vì đã cho tui biết.\n"
	.string "Bởi lẽ đó, bạn xứng đáng nhận cái này.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} nhận HUY HIỆU NHIỆT\n"
	.string "từ HOẢ LY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Nếu có HUY HIỆU NHIỆT, tất cả POKéMON,\n"
	.string "kể cả những con nhận được khi đổi với\l"
	.string "người khác, sẽ nghe lời bạn cho tới\l"
	.string "Cấp 50.\p"
	.string "Ngoài ra, nó còn cho phép POKéMON\n"
	.string "thi triển SỨC LỰC ngoài ván đấu.\p"
	.string "Đây là tấm lòng của tui.\n"
	.string "Cứ nhận lấy đi, đừng ngại!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "TM50 có chứa QUÁ NHIỆT.\p"
	.string "Chiêu thức gây ST rất lớn\n"
	.string "lên đối thủ.\p"
	.string "Nhưng mà nó cũng sẽ giảm mạnh ST.PHÉP\n"
	.string "của POKéMON thi triển. Nó không phù\l"
	.string "hợp cho trận đấu kéo dài đâu.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "Lưu số CHỦ GYM HOẢ LY\n"
	.string "vô BẢN ĐỒ.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Sức mạnh của bạn làm tui nhớ tới…\p"
	.string "À! Biết rồi! Bạn thách đấu cứ\n"
	.string "như THƯỜNG, CHỦ GYM HOA CAM vậy.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "NHÀ THI ĐẤU THỊ TRẤN NÚI LỬA$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "NHÀ THI ĐẤU THỊ TRẤN NÚI LỬA\p"
	.string "HOẢ LY CÔNG NHẬN CHO NHL:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "HOẢ LY: Thua một trận không\n"
    .string "làm tui nản lòng.\p"
    .string "Tui yêu POKéMON.\n"
    .string "Tui thích thi đấu.\l"
    .string "Và… tui yêu cái GYM này!\p"
	.string "Hãy cùng trao đổi những chiêu thức\n"
    .string "cháy bỏng trong trận này!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Phù!\n"
	.string "Sắp phun trào tới nơi rồi!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "HOẢ LY: Tui thua trận,\n"
	.string "nhưng mà tui mãn nguyện rồi.\p"
	.string "Không phải lúc nào tui cũng\n"
	.string "có trận đấu nảy lửa giống vậy đâu.\p"
	.string "Hẹn gặp dịp khác,\n"
	.string "tái đấu 1 trận như vầy nữa nha!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "HOẢ LY: Thua một trận không\n"
    .string "làm tui nản lòng.\p"
    .string "Tui yêu POKéMON.\n"
    .string "Tui thích thi đấu.\l"
    .string "Và… tui yêu cái GYM này!\p"
	.string "Hãy cùng trao đổi những chiêu thức\n"
    .string "cháy bỏng trong trận này!$"
	.string "Ủa khoan. Bạn chỉ có 1 POKéMON\n"
	.string "để đấu thôi hả?\p"
	.string "Đừng có bắt tui phải nói chứ, ít\n"
	.string "nhất cũng đem nhiều hơn 2 POKéMON đi.$"
