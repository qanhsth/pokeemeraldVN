MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Ta cũng muốn thấy GROUDON nữa, mà\n"
	.string "tụi nó không cho, kể cả là cái đuôi…\p"
	.string "Bởi vậy ta mới khó chịu quá trời.\p"
	.string "Ủa, mà!\n"
	.string "Ta vừa hoạch tẹt về GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Ta nghĩ sẽ không thể thắng\n"
	.string "nếu không kìm chế được cảm xúc…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Không biết GROUDON có đuôi không nữa?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Sớm thôi! Sẽ sớm thôi!\l"
	.string "Đại mục tiêu sẽ đạt được!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grừưưư…\n"
	.string "Ta đã cố lắm rồi, mà?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "Thưa ngài MÃ!\n"
	.string "Có tên đột nhập tính cản đường ông!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Chưa có xong đâu!\n"
	.string "Không có dễ qua mặt được ta đâu!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Ủa ta dễ bị hạ lắm hả?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "Thôi, trận nữa đi nè…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe!\n"
	.string "Ngươi đã tới được đây, thôi để ta kể!\p"
	.string "Đúng rồi đó!\n"
	.string "Phía trước, GROUDON đang ngủ say!\p"
	.string "Ông MÃ vừa mới tới chỗ GROUDON\n"
	.string "tức thì!\p"
	.string "Nó sẽ sớm được thức tỉnh thôi!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Bị hạ nữa rồi…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…Trong lúc ngươi ở đây với ta,\n"
	.string "ông MÃ đã đánh thức GROUDON rồi…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MÃ: GROUDON…\p"
	.string "Không gì có thể đánh thức được\n"
	.string "ngươi, đang ngủ say trong dung nham…\p"
	.string "Viên NGỌC XANH là thứ mà ngươi muốn.\n"
	.string "Có phải không?\p"
	.string "Ta đem tới cho ngươi viên NGỌC XANH.\n"
	.string "Để ánh sáng của nó đánh thức ngươi!\p"
	.string "Rồi hãy cho ta coi…\n"
	.string "Sức mạnh tối đa của ngươi!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MÃ: GROUDON!\n"
	.string "Sao vậy?\p"
	.string "Không phải NGỌC XANH hả?\p"
	.string "GROUDON!\n"
	.string "Ngươi đi đâu vậy…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MÃ: Ủa, lại là nhà ngươi?\p"
	.string "Ta thấy ngươi lén lút đi\n"
    .string "loanh quanh ở đây…\p"
    .string "Giờ thì ta đã hiểu!\n"
    .string "Chắc ngươi đã xài trò rẻ tiền nào đó!$"

MagmaHideout_4F_Text_MaxieDefeat:
    .string "Điều gì làm ngươi giỏi đối phó\n"
    .string "với POKéMON tới vậy?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MÃ: Phải có lý do mà\n"
	.string "GROUDON lại bỏ đi…\p"
	.string "Đó là điều ngươi muốn nói,\n"
	.string "có phải không?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hừm…\n"
	.string "Ngươi nghĩ là ta không biết?\p"
	.string "GROUDON mà bỏ đi, thì không còn\n"
	.string "gì để làm ở núi lửa này nữa.\p"
	.string "Ta sẽ đuổi theo GROUDON, vậy nên\n"
	.string "ta chia cắt nhau tại đây!$"
