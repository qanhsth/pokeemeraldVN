VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Để tui coi POKéMON cho bạn.\n"
	.string "Coi thử nó có thích bạn không.\p"
	.string "Trời.\n"
	.string "POKéMON của bạn…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "Nó mến bạn.\n"
	.string "Nó yêu quý bạn tới mức không hơn được nữa.\l"
	.string "Tui thậm chí còn thấy hạnh phúc thay.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "Nhìn nó rất vui.\n"
	.string "Tất nhiên nó yêu quý bạn rất nhiều.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "Hình như nó thích bạn nhiều lắm.\n"
	.string "Nó muốn được bạn ôm ắp như em bé.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "Nó đã dần quen với bạn.\n"
	.string "Nó tin tưởng bạn.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "Nó chưa quen với bạn lắm.\n"
	.string "Nó không thích cũng không ghét bạn.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "Nó rất cảnh giác.\n"
    .string "Đôi mắt nó nhìn rất dữ.\l"
	.string "Nó không thích bạn xíu nào.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "Cái này hơi khó nói…\p"
	.string "Nó rất là ghét bạn.\n"
	.string "Bạn có làm nó khó chịu hay gì không?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU: Pì ka pi ka!$"

