LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks:
	.string "Ủa, trời ơi! Con đi một mình hả?\n"
	.string "Trẻ vậy mà! Giỏi ghê!\p"
	.string "Chắc chắn mấy đứa con cô sẽ\n"
	.string "học được 1 hoặc 2 điều từ con!\p"
	.string "Cô hả? Cô là thầy {POKEBLOCK}.\p"
	.string "Nếu mà nghiêm túc một chút, thì,\n"
	.string "cô sẽ tạo ra được nhiều {POKEBLOCK}.\p"
	.string "Con có muốn học hỏi một chút,\n"
	.string "từ sư thầy {POKEBLOCK} không?$"

LilycoveCity_House3_Text_OhAreYouSure:
	.string "Ủa? Con chắc chưa?\p"
	.string "Con không nên làm mọi\n"
	.string "thứ một mình đâu, con ơi!$"

LilycoveCity_House3_Text_ExplainPokeblocks:
	.string "Giỏi! Ngoan!\n"
	.string "Cái này hơi dài, mà ráng nghe đi!\p"
	.string "Con sẵn sàng chưa?\p"
	.string "Nhìn vô thanh {POKEBLOCK}, con sẽ thấy\n"
	.string "nó được đánh giá dựa trên vị giác.\p"
	.string "Vị càng nhẹ,\n"
	.string "thì càng ngon. Nhớ nha!\p"
	.string "Một viên kẹo {POKEBLOCK} tốt sẽ có\n"
	.string "vị nhẹ và mức độ cao.\p"
	.string "POKéMON có thể ăn nhiều {POKEBLOCK}\n"
	.string "loại tốt hơn loại thường.\p"
	.string "Cái này quan trọng nè.\p"
	.string "Nếu muốn làm {POKEBLOCK} ngon,\n"
	.string "thì bỏ nhiều loại TRÁI CÂY vô.\p"
	.string "Đừng có nhím--bỏ nhiều loại TRÁI CÂY\n"
	.string "vô sẽ tăng độ ngon cho {POKEBLOCK}.\p"
	.string "Còn một cái nữa.\p"
	.string "Càng nhiều người xay TRÁI CÂY,\n"
	.string "thì {POKEBLOCK} sẽ càng ngon hơn.\p"
	.string "Bởi vậy con phải đi lại hỏi\n"
	.string "người ta, kêu họ làm {POKEBLOCK} chung.\p"
	.string "Đó là tất cả những gì cần biết\n"
	.string "để làm kẹo {POKEBLOCK} ngon.\p"
	.string "Nếu người ta POKéMON để yêu quý,\n"
	.string "nhiều viên {POKEBLOCK} ngon, và gia đình\l"
	.string "ấm cúng, thế giới sẽ đẹp hơn biết bao.\p"
	.string "Cố lên con ơi!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets:
	.string "Hồi mà vợ chú sanh tư,\n"
	.string "chú cũng hơi lo.\p"
	.string "Mà giờ thấy tụi nhỏ chơi vui vậy,\n"
	.string "chú cũng mừng.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles:
	.string "Tụi tui sẽ có trận đấu NHIỀU NGƯỜI\n"
	.string "mà kiểu gì tụi tui cũng thắng thôi.$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner:
	.string "Tụi tui thích xáo trộn\n"
	.string "thông tin ở KHU GHI HÌNH.\p"
	.string "Nhưng mà cái nào sẽ bị xáo trộn?$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender:
	.string "Tụi tui sẽ làm ra thiệt nhiều\n"
	.string "kẹo {POKEBLOCK} bằng MÁY XAY TRÁI CÂY!$"

LilycoveCity_House3_Text_GoingToEnterContest:
	.string "Tui muốn khoe cho người ta biết\n"
	.string "sức mạnh của POKéMON, nên là\l"
	.string "tụi tui tính đi đăng ký THI.$"

