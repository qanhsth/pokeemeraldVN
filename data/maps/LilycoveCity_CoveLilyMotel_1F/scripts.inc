LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_MOTEL_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hửm, vậy là họ xài POKéMON\n"
	.string "để thu hút thêm khách tới sao?\p"
	.string "Hửm, ừm, chắc tui cũng kiếm con POKéMON\n"
	.string "cưng cưng làm linh vật cho trọ của tui.\p"
	.string "Không biết là như vậy có\n"
	.string "kiếm được thêm khách nào không?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Ủa, xin lỗi, xin lỗi nha!\n"
	.string "Tui mắc coi tivi không để ý!\p"
	.string "Từ lúc mà ĐỘI AQUA tới,\n"
	.string "du khách ít ghé qua lắm.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Ê, né coi!\n"
	.string "Đứng đó sao tui coi tivi được!$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Hay quá! Bạn nói là POKéMON\n"
	.string "kiếm được đồ cho người ta hả?\p"
	.string "Cái này hay nha. Nếu mà có\n"
	.string "POKéMON thông minh được vậy…\p"
	.string "Tụi tui sẽ phục hồi lại\n"
	.string "sự mất mát cho khách hàng…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Ủa, xin lỗi, xin lỗi nha!\n"
	.string "Tui mắc coi tivi không để ý!\p"
	.string "Nghe nói có người đã đột kích\n"
    .string "vô CĂN CỨ của ĐỘI AQUA.\p"
    .string "Nhờ vậy mà, tụi tui vừa nhận được một\n"
    .string "đơn đặt phòng từ một nhóm nhiều người.\p"
    .string "Đó là một công ty tên là… ờm…\n"
    .string "GAME gì đó…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Hay quá! POKéMON coi nhà\n"
    .string "mà bắt được ăn trộm luôn?\p"
    .string "Hay á chứ. Nếu mà có một con\n"
    .string "con POKéMON mạnh mẽ làm bảo vệ…\p"
    .string "Tụi tui sẽ có thể bảo đảm\n"
    .string "an toàn cho khách hàng.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Ủa, xin lỗi, xin lỗi nha!\n"
	.string "Tui mắc coi tivi không để ý!\p"
	.string "À, đúng rồi. Có một nhóm nhiều người\n"
	.string "mới tới tức thì.\p"
	.string "Họ đặt tên là GAME FREAK,\n"
	.string "chắc họ làm game hay sao á.\p"
	.string "Ủa quên, thôi tui đi chuẩn bị\n"
	.string "cơm tối cho người ta đây!$"

