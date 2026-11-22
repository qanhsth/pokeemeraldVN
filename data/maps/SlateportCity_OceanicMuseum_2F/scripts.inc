SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_1, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_MUSEUM_2, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OCEANIC_MUSEUM_2F_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_OCEANIC_MUSEUM_2F_ARCHIE
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_1
	removeobject LOCALID_OCEANIC_MUSEUM_2F_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	removeobject LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_OCEANIC_MUSEUM_2F_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement LOCALID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Ơi? Nếu bạn đang kiếm SANG,\n"
	.string "thì người đó là tui đây.\p"
	.string "À! Mấy linh kiện này tui đặt\n"
	.string "mua từ ÔNG THẠCH ở DEVON.\p"
	.string "Cảm ơn nha! Tốt rồi!\n"
	.string "Tụi tui có thể chuẩn bị thám hiểm rồi.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Hehehe, cầm giùm cái!\n"
	.string "Để tui lấy đồ ra!$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "THUYỀN TRƯỞNG: H-Hả?\n"
	.string "Mấy người là ai vậy?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Tụi ta là ĐỘI AQUA!\p"
	.string "ÔNG TRÙM muốn có mấy cái linh kiện này!\n"
	.string "Im miệng và đưa đây cho ta!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Awaaaah!\n"
	.string "Tui bị con nít đánh bại rồi!$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Trời, thảm hại quá…\n"
	.string "ÔNG TRÙM sẽ tức giận cho mà coi…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Humph, tên nhát gan!\n"
	.string "Để ta lo!$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Hả?!\n"
	.string "Ta cũng thua sao!$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Giờ sao? Nếu không lấy linh kiện được,\n"
	.string "ta sẽ gặp rắc rối đó!\p"
	.string "Arrgh, không ngờ lại bị đứa con nít\n"
	.string "xen vô phá đám!$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Ta tới để coi sao mà lấy có mấy cái\n"
	.string "linh kiện mà lâu vậy, thì các ngươi\l"
	.string "lại thua một đứa con nít sao?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Tụi ta là ĐỘI AQUA,\n"
	.string "và tụi ta yêu biển cả!\p"
	.string "Ta là THỦ LĨNH ĐỘI AQUA,\n"
	.string "MUỘI!\p"
	.string "Tại sao ngươi lại cản trở tụi ta?\p"
	.string "…Không! Ngươi không thể là!\n"
	.string "Ngươi không phải người của MAGMA sao?\p"
	.string "Ừ, cũng đúng.\n"
	.string "Ngươi không hợp vai phản diện cho lắm.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, con người… Tất cả sự sống\n"
	.string "đều phụ thuộc vào biển.\p"
	.string "Cho nên ĐỘI AQUA có trách nhiệm\n"
	.string "mở rộng biển.\p"
	.string "Ngươi có đồng ý? Chuyện mà tụi ta\n"
	.string "đang làm thật vĩ đại.\p"
	.string "À phải rồi…\n"
	.string "Ngươi vẫn còn quá trẻ để\l"
	.string "hiểu được mục tiêu to lớn của tụi ta.\p"
	.string "Nhưng mà, ta cảnh cáo nhà ngươi,\n"
	.string "đừng bao giờ xía vô chuyện của tụi ta.\p"
	.string "Ngươi sẽ phải\n"
	.string "trả giá đắt đó!\p"
	.string "Đừng có quên điều đó!$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "THUYỀN TRƯỞNG: Bạn là…\n"
	.string "Ah, bạn là {PLAYER}…\p"
	.string "Tình huống hồi nãy căng thẳng quá!\n"
	.string "Cảm ơn vì đã cứu tụi tui!\p"
	.string "À mà tui xém quên là bạn\n"
	.string "có đem theo linh kiện từ DEVON!$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "THUYỀN TRƯỞNG: Whoops!\n"
	.string "Không còn thời gian chần chừ nữa!\p"
    .string "Tụi tui phải lên đường cho chuyến\n"
    .string "thám hiểm dưới biển ngay lập tức.\p"
    .string "Cảm ơn lần nữa, nhưng giờ tui\n"
    .string "phải đi rồi!\p"
	.string "Mà bạn cứ tham quan, khám phá\n"
    .string "thoải mái các cơ sở của tụi tui nha.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "Tui có thấy mô hình một con tàu ở đây.\p"
	.string "Làm tui nhớ tới TÀU BỎ HOANG ở\n"
	.string "gần THÔN ĐẢO…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "Đừng có chạy lòng vòng trong\n"
	.string "THƯ VIỆN!$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Trời, cái tàu ngầm đó đã thiệt!\n"
	.string "Tui muốn đi thử 1 vòng quá!$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "“MẪU THỬ NƯỚC 1,” nhãn hiệu\n"
	.string "nói vậy đó.\p"
	.string "Biển là một thể thống nhất, nhưng nước\n"
    .string "dường như khác nhau tùy theo từng vùng.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "“MẪU THỬ NƯỚC 2,” nhãn hiệu\n"
	.string "nói vậy đó.\p"
	.string "Độ mặn nước biển có khác nhau\n"
	.string "theo từng vùng không?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Một quả cầu cao su đang giãn nở và\n"
    .string "co lại.\p"
    .string "“Trong biển, chính trọng lượng của nước\n"
    .string "tạo ra áp suất.\p"
    .string "“Ở vùng nước cạn, áp suất không\n"
    .string "quá lớn.\p"
	.string "“Tuy nhiên, ở vùng nước cực sâu,\n"
    .string "áp suất có thể lên tới hàng chục\l"
    .string "ngàn tấn trên một diện tích nhỏ.”$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“MÔ PHỎNG VÙNG HOENN”\p"
	.string "Đây là một mô hình thu nhỏ của\n"
    .string "vùng HOENN.\p"
    .string "THỊ TRẤN MỸ BẠCH nằm ở đâu ta?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "Mô hình minh hoạ dòng chảy nước biển.\p"
    .string "“Ở gần đáy biển, nước chảy\n"
    .string "thay đổi do sự chênh lệch của các\l"
    .string "yếu tố như nhiệt độ và độ mặn.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "Mô hình minh hoạ dòng chảy nước biển.\p"
	.string "“Nước biển chảy về phía bề mặt dưới tác\n"
    .string "động của các dòng hải lưu do gió tạo ra.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“BẾN PHÀ S.S. TIDAL\p"
	.string "“Mô hình thu nhỏ con tàu đang được\n"
	.string "đóng tại XƯỞNG ĐÓNG TÀU của SANG.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“TÀU KAIEN SỐ 1\p"
	.string "“Một bản sao của chiếc tàu ngầm\n"
    .string "thám hiểm đáy đại dương hiệu suất cao.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“THIẾT BỊ TÀU NGẦM\p"
    .string "“Mô hình thu nhỏ, không người lái\n"
    .string "dùng để thám hiểm đáy biển.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“TÀU THÁNH ANNA\p"
	.string "“Bản sao của con tàu du lịch sang trọng\n"
    .string "đi đang vòng quanh thế giới.”$"

