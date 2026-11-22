SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement LOCALID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE_SLEEPING
	addobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_SEAFLOOR_CAVERN_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_SEAFLOOR_CAVERN_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_SEAFLOOR_CAVERN_ARCHIE
	setvar VAR_0x8005, LOCALID_SEAFLOOR_CAVERN_MAXIE
	setvar VAR_0x8006, LOCALID_SEAFLOOR_CAVERN_GRUNT_1
	setvar VAR_0x8007, LOCALID_SEAFLOOR_CAVERN_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_ROUTE128_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
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

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "MUỘI: Đứng lại đó.$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "MUỘI: Fufufu…\n"
	.string "Lại là ngươi.$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "MUỘI: Nhìn đi!\p"
	.string "Thứ sinh vật lộng lẫy, tồn tại từ\n"
	.string "rất lâu về trước, đang nằm ngủ, KYOGRE!\p"
	.string "Ta đã chờ ngày này tới\n"
	.string "từ lâu rồi…$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "MUỘI: Cũng ngạc nhiên, khi mà\n"
	.string "ngươi đuổi kịp ta tới đây.\p"
	.string "Nhưng mà mọi thứ đã kết thúc.\p"
	.string "Để hiện thực hoá giấc mơ của ta,\n"
	.string "nhà ngươi phải biến mất ngay lập tức!$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "Hả?!\n"
	.string "Ta mà lại thua một đứa nhóc như ngươi?!$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.string "MUỘI: Fufufu…\p"
	.string "Ta phải khen ngươi. Phải công nhận\n"
	.string "là ngươi thực sự có tài.\p"
	.string "Nhưng!\n"
	.string "Ta đang giữ cái này!\p"
	.string "Với NGỌC ĐỎ này, ta có thể làm KYOGRE…$"

SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.string "Cái NGỌC ĐỎ tự nhiên\n"
	.string "phát sáng lên!$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "MUỘI: Hả?!\p"
	.string "Ta có làm gì đâu.\n"
	.string "Sao cái NGỌC ĐỎ lại…\p"
	.string "KYOGRE đi đâu rồi?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "MUỘI: Hửm? Có lời nhắn từ\n"
	.string "thành viên bên ngoài…$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "MUỘI: Ừ, sao vậy?\p"
	.string "Hừm…\n"
	.string "Mưa lớn lắm hả?\p"
	.string "Tốt… Chuyện đó phải xảy ra.\n"
	.string "Đó là lý do tại sao ta lại đánh thức\l"
	.string "KYOGRE, để nhận ra tầm nhìn khai mở biển\l"
	.string "của ĐỘI AQUA.\p"
	.string "Hả?!\p"
	.string "Mưa còn nặng hơn ta tưởng?\n"
	.string "Các ngươi đang gặp nguy?\p"
	.string "Không thể…\n"
	.string "Không thể nào như vậy được…\p"
	.string "Giữ vị trí,\n"
	.string "quan sát tình hình đi!$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "MUỘI: Có gì đó không ổn…\p"
	.string "Cái NGỌC ĐỎ lẽ ra phải đánh thức\n"
	.string "và kiểm soát KYOGRE…\p"
	.string "Nhưng mà… Tại sao vậy?\n"
	.string "Tại sao KYOGRE lại biến mất?\p"
	.string "Tại sao vậy?!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.string "MÃ: Ngươi đã làm cái gì vậy?\p"
	.string "MUỘI… Ngươi thực sự đã đánh thức KYOGRE,\n"
	.string "phải không?\p"
	.string "Thế giới sẽ ra sao nếu cơn mưa xối xả\n"
    .string "này cứ tiếp diễn mãi mãi?\p"
    .string "Các lục địa trên thế giới sẽ chìm\n"
    .string "trong nước biển, ngày càng sâu…$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.string "MUỘI: H-hả?!\n"
	.string "Đừng có ra vẻ cao ngạo với ta như vậy!\p"
	.string "Chẳng phải chính MAGMA các ngươi, là\n"
    .string "những kẻ đã khiến GROUDON nổi giận sao?\p"
    .string "Chừng nào ta còn giữ được NGỌC ĐỎ này,\n"
    .string "ta sẽ còn kiểm soát được KYOGRE…\p"
    .string "Ta sẽ có thể kiểm soát nó…$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.string "MÃ: Chúng ta không còn thì giờ\n"
	.string "để tranh cãi nữa!\p"
	.string "Cứ tự đi ra ngoài mà coi!\p"
	.string "Tự mà coi cái thế giới mà chúng ta\n"
	.string "khát khao bị phá hoại tới mức nào!$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.string "MÃ: {PLAYER}, thôi, ngươi cũng\n"
	.string "nên thoát khỏi đây đi!$"
