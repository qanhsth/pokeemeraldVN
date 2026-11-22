SlateportCity_OceanicMuseum_1F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_1F_EventScript_EntranceAttendant::
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeLeft::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFeeRight::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee
	end

SlateportCity_OceanicMuseum_1F_EventScript_PayEntranceFee::
	showmoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_CheckMoneyForFee::
	checkmoney 50
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney
	playse SE_SHOP
	removemoney 50
	updatemoneybox
	msgbox SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_NotEnoughMoney::
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway
	msgbox SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter
	waitmovement 0
	releaseall
	end

SlateportCity_OceanicMuseum_1F_EventScript_AllowEntranceAnyway::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end

SlateportCity_OceanicMuseum_1F_Movement_PushPlayerBackFromCounter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt5::
	msgbox SlateportCity_OceanicMuseum_1F_Text_RustboroBungled, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumGrunt6::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_WhirlpoolExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_WaterfallExperiment::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanSoilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_BeachSandDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_OceanicMinifact3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_FossilDisplay::
	msgbox SlateportCity_OceanicMuseum_1F_Text_FossilDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_DepthMeasuringMachine::
	msgbox SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron3::
	msgbox SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_MuseumPatron4::
	msgbox SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGrunt::
	lock
	faceplayer
	delay 8
	playse SE_PIN
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_THIEF
	goto_if_eq VAR_RESULT, 0, SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief
	setflag FLAG_RECEIVED_TM_THIEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth
	goto_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	goto_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitNorth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitSouth::
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExitWestEast::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast
	applymovement LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT, SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited
	end

SlateportCity_OceanicMuseum_1F_EventScript_FamiliarGruntExited::
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	playse SE_EXIT
	removeobject LOCALID_OCEANIC_MUSEUM_FAMILIAR_GRUNT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_NoRoomForThief::
	msgbox SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_PlayerWatchGruntExitWestEast:
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExit:
	face_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Movement_FamiliarGruntExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

SlateportCity_OceanicMuseum_1F_Text_WouldYouLikeToEnter:
	.string "Chào mừng đến với BẢO TÀNG BIỂN SÂU.\p"
	.string "Vé tham quan là ¥50.\n"
	.string "Bạn có muốn vô không?$"

SlateportCity_OceanicMuseum_1F_Text_PleaseEnjoyYourself:
	.string "Tham quan thoải mái đi.$"

SlateportCity_OceanicMuseum_1F_Text_NotEnoughMoney:
	.string "Ủa? Xin lỗi nhưng mà hình như\n"
	.string "bạn không có đem đủ tiền.$"

SlateportCity_OceanicMuseum_1F_Text_CatchUpWithYourGroup:
	.string "Ủa? Bạn phải đi chung với nhóm\n"
	.string "hồi nãy không?\p"
	.string "Có mình bạn là trễ đó.\n"
	.string "Lẹ lẹ đi để thôi không kịp!$"

SlateportCity_OceanicMuseum_1F_Text_AquaExistForGoodOfAll:
	.string "ĐỘI AQUA hoạt động vì\n"
	.string "lợi ích của nhân loại!$"

SlateportCity_OceanicMuseum_1F_Text_OurBossIsntHere:
	.string "Tụi tui được kêu tập hợp lại đây,\n"
	.string "thì tụi tui cũng đã đứng đây rồi…\p"
	.string "Mà ÔNG TRÙM thì lại chưa tới.$"

SlateportCity_OceanicMuseum_1F_Text_WouldStuffHereMakeMeRich:
	.string "Nếu lấy hết đồ ở đây đem bán,\n"
	.string "thì tui có giàu lên được không?$"

SlateportCity_OceanicMuseum_1F_Text_CanLearnForNefariousDeeds:
	.string "Những gì học được ở đây tui sẽ\n"
	.string "áp dụng vô những chuyện xấu xa…$"

SlateportCity_OceanicMuseum_1F_Text_RustboroBungled:
	.string "Nếu mà tụi lính dưới không làm hư chuyện\n"
	.string "ở KIM THÁN, thì ta không bị điều tới đây!$"

SlateportCity_OceanicMuseum_1F_Text_DidntHaveMoney:
	.string "Tui không có ¥50, bởi vậy nên phải\n"
	.string "chờ rất là lâu ở quầy tiếp tân.$"

SlateportCity_OceanicMuseum_1F_Text_LearnAboutSeaForBattling:
	.string "Tui muốn học về biển cả\n"
	.string "để áp dụng cho chuyện chiến đấu.$"

SlateportCity_OceanicMuseum_1F_Text_SternIsRoleModel:
	.string "Tui cảm thấy phấn khích và xao xuyến khi\n"
    .string "tui nhìn thấy biển!\p"
	.string "Đối với tui, THUYỀN TRƯỞNG SANG là\n"
	.string "hình mẫu lý tưởng nhất!$"

SlateportCity_OceanicMuseum_1F_Text_MustBePokemonWeDontKnow:
	.string "Biển cả bao la vô tận, và\n"
    .string "sâu thẳm vô cùng…\p"
	.string "Chắc hẳn có rất nhiều POKéMON mà\n"
	.string "ta chưa biết tới.$"

SlateportCity_OceanicMuseum_1F_Text_WantSeaPokemon:
	.string "Tui muốn có 1 con POKéMON vùng biển.\p"
	.string "Tui nghĩ là nếu được ôm nó thì\n"
	.string "sẽ rất là mát.$"

SlateportCity_OceanicMuseum_1F_Text_RememberMeTakeThis:
	.string "Aiyeeeh!\n"
	.string "Ngươi đang làm gì ở đây?\p"
	.string "Ta hả? Ta là người của AQUA, bị\n"
	.string "ngươi đánh bại hồi trước, nhớ không?\l"
	.string "ĐƯỜNG HẦM KIM CHI á?\p"
	.string "Đây, cầm đi!\n"
	.string "Hãy tha lỗi cho ta!$"

SlateportCity_OceanicMuseum_1F_Text_HopeINeverSeeYouAgain:
	.string "Cái TM đó, sẽ giúp ích được\n"
	.string "cho ngươi.\p"
	.string "Mong là ta sẽ không gặp lại ngươi nữa!\n"
	.string "Wahahaha!$"

SlateportCity_OceanicMuseum_1F_Text_YouHaveToTakeThis:
	.string "Trời, sao dạ?\n"
	.string "Cầm lấy để ta còn đi chỗ khác nữa chứ!$"

SlateportCity_OceanicMuseum_1F_Text_WhirlpoolExperiment:
	.string "Một chất lỏng màu xanh đang xoáy tròn\n"
	.string "trong bình thuỷ tinh.\p"
	.string "“Đây là thí nghiệm để tạo ra\n"
	.string "XOÁY NƯỚC nhân tạo bằng gió.”$"

SlateportCity_OceanicMuseum_1F_Text_WaterfallExperiment:
	.string "Một quả cầu đỏ đang lắc lư lên xuống\n"
	.string "trong bình thuỷ tinh.\p"
	.string "“Đây là thí nghiệm mô phỏng\n"
	.string "LEO THÁC bằng cách tận dụng lực nổi.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanSoilDisplay:
	.string "Đây là mẫu đất lấy từ\n"
    .string "đáy đại dương.\p"
    .string "“Trong suốt nhiều năm, tàn tích của\n"
    .string "các sinh vật lắng đọng dưới đáy\l"
    .string "biển, tạo thành các lớp trầm tích.\p"
	.string "“Bằng cách phân tích các lớp này,\n"
    .string "quá khứ xa xưa dần được hé lộ.”$"

SlateportCity_OceanicMuseum_1F_Text_BeachSandDisplay:
	.string "Đây là một mẫu cát bãi biển.\p"
    .string "“Những hòn đá trên núi bị nước\n"
    .string "sông cuốn trôi xuống, nên bị\l"
    .string "mài mòn và nghiền nát.\p"
    .string "“Tụi nó bị nghiền thành những hạt nhỏ và\n"
    .string "cuối cùng trở thành cát trên bãi biển.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact1:
	.string "“BÍ MẬT BIỂN SÂU 1\n"
    .string "Tại sao nước biển có màu xanh?\p"
	.string "“Ánh sáng bao gồm nhiều màu sắc.\p"
    .string "“Khi ánh sáng đi qua nước,\n"
    .string "hầu hết các loại ánh sáng đều mất màu.\p"
    .string "“Tuy nhiên, ánh sáng màu xanh vẫn\n"
    .string "còn giữ lại được, nên biển có màu xanh.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact2:
	.string "“BÍ MẬT BIỂN SÂU 2\n"
	.string "Tại sao nước biển lại mặn?\p"
	.string "“Nước biển chứa muối hòa tan dưới dạng\n"
    .string "các ion natri và clo.\p"
    .string "“Các ion này được rửa trôi khỏi đá\n"
    .string "và tràn xuống biển khi mưa xuống.\p"
    .string "“Nồng độ muối hòa tan\n"
    .string "khiến biển có vị mặn.”$"

SlateportCity_OceanicMuseum_1F_Text_OceanicMinifact3:
	.string "“BÍ MẬT BIỂN SÂU 3\n"
	.string "Cái nào lớn hơn? Biển hay đất liền?\p"
    .string "“Biển chiếm khoảng 70% diện tích\n"
    .string "trái đất, và phần còn lại là đất liền.\p"
    .string "“Do đó, diện tích biển lớn hơn gấp đôi\n"
    .string "diện tích đất liền.”$"

SlateportCity_OceanicMuseum_1F_Text_FossilDisplay:
	.string "Đây là hoá thạch có đường gợn sóng.\p"
    .string "“Đất ở dưới biển bị xói mòn\n"
    .string "bởi thủy triều.\p"
    .string "“Dòng chảy của nước biển làm cho đất\n"
    .string "có đường gợn sóng và lỗ thủng nhỏ.\p"
	.string "“Nếu lớp đất này hoá thạch, nó sẽ\n"
    .string "được gọi là vết gợn sóng.”$"

SlateportCity_OceanicMuseum_1F_Text_DepthMeasuringMachine:
	.string "Một cỗ máy kỳ lạ đang quay dưới\n"
    .string "một mái vòm bằng kiếng.\p"
    .string "Có lẽ nó dùng để đo độ sâu\n"
    .string "của thứ gì đó…$"

