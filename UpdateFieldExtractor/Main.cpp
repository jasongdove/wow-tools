
#include "Export.h"
#include <Windows.h>

enum UpdateFieldSizes : std::uint32_t
{
    OBJECT_COUNT                = 8,
    OBJECT_DYNAMIC_COUNT        = 0,
    ITEM_COUNT                  = 61,
    ITEM_DYNAMIC_COUNT          = 1,
    CONTAINER_COUNT             = 73,
    CONTAINER_DYNAMIC_COUNT     = 0,
    UNIT_COUNT                  = 152,
    UNIT_DYNAMIC_COUNT          = 2,
    PLAYER_COUNT                = 1827,
    PLAYER_DYNAMIC_COUNT        = 3,
    GAMEOBJECT_COUNT            = 12,
    GAMEOBJECT_DYNAMIC_COUNT    = 0,
    DYNAMICOBJECT_COUNT         = 6,
    DYNAMICOBJECT_DYNAMIC_COUNT = 0,
    CORPSE_COUNT                = 28,
    CORPSE_DYNAMIC_COUNT        = 0,
    AREATRIGGER_COUNT           = 6,
    AREATRIGGER_DYNAMIC_COUNT   = 0,
    SCENEOBJECT_COUNT           = 5,
    SCENEOBJECT_DYNAMIC_COUNT   = 0,
    CONVERSATION_COUNT          = 0,
    CONVERSATION_DYNAMIC_COUNT  = 0
};

namespace Offsets
{
    std::uintptr_t const ObjectFields = 0xCFB720;
    std::uintptr_t const ItemFields = 0xCFB780;
    std::uintptr_t const ItemDynamicFields = 0xCFC15C;
    std::uintptr_t const ContainerFields = 0xCFBA5C;
    std::uintptr_t const UnitFields = 0xCFB000;
    std::uintptr_t const UnitDynamicFields = 0xCFA86C;
    std::uintptr_t const PlayerFields = 0xCF52B8;
    std::uintptr_t const PlayerDynamicFields = 0xCEF578;
    std::uintptr_t const GameObjectFields = 0xCEF4C0;
    std::uintptr_t const GameObjectDynamicFields = 0x000000;
    std::uintptr_t const DynamicObjectFields = 0xCEF378;
    std::uintptr_t const CorpseFields = 0xCEF180;
    std::uintptr_t const AreaTriggerFields = 0xCEEF88;
    std::uintptr_t const SceneObjectFields = 0xCEEEA4;
    std::uintptr_t const ConversationFields = 0x000000;
    std::uintptr_t const ConversationDynamicFields = 0x000000;
}

int main()
{
    HMODULE dll = LoadLibraryA("UpdateFieldExtractorLib.dll");
    if (!dll)
        return 1;

    ExportFn extract = (ExportFn)GetProcAddress(dll, "Extract");
    if (!extract)
    {
        FreeLibrary(dll);
        return 1;
    }

    UpdateFieldOffsets offsets;
    memset(&offsets, 0, sizeof(offsets));
    offsets.ObjectFields = Offsets::ObjectFields;
    offsets.ObjectCount = OBJECT_COUNT;
    offsets.ItemFields = Offsets::ItemFields;
    offsets.ItemDynamicFields = Offsets::ItemDynamicFields;
    offsets.ItemCount = ITEM_COUNT;
    offsets.ItemDynamicCount = ITEM_DYNAMIC_COUNT;
    offsets.ContainerFields = Offsets::ContainerFields;
    offsets.ContainerCount = CONTAINER_COUNT;
    offsets.UnitFields = Offsets::UnitFields;
    offsets.UnitDynamicFields = Offsets::UnitDynamicFields;
    offsets.UnitCount = UNIT_COUNT;
    offsets.UnitDynamicCount = UNIT_DYNAMIC_COUNT;
    offsets.PlayerFields = Offsets::PlayerFields;
    offsets.PlayerDynamicFields = Offsets::PlayerDynamicFields;
    offsets.PlayerCount = PLAYER_COUNT;
    offsets.PlayerDynamicCount = PLAYER_DYNAMIC_COUNT;
    offsets.GameObjectFields = Offsets::GameObjectFields;
    offsets.GameObjectDynamicFields = Offsets::GameObjectDynamicFields;
    offsets.GameObjectCount = GAMEOBJECT_COUNT;
    offsets.GameObjectDynamicCount = GAMEOBJECT_DYNAMIC_COUNT;
    offsets.DynamicObjectFields = Offsets::DynamicObjectFields;
    offsets.DynamicObjectCount = DYNAMICOBJECT_COUNT;
    offsets.CorpseFields = Offsets::CorpseFields;
    offsets.CorpseCount = CORPSE_COUNT;
    offsets.AreaTriggerFields = Offsets::AreaTriggerFields;
    offsets.AreaTriggerCount = AREATRIGGER_COUNT;
    offsets.SceneObjectFields = Offsets::SceneObjectFields;
    offsets.SceneObjectCount = SCENEOBJECT_COUNT;
    offsets.ConversationFields = Offsets::ConversationFields;
    offsets.ConversationDynamicFields = Offsets::ConversationDynamicFields;
    offsets.ConversationCount = CONVERSATION_COUNT;
    offsets.ConversationDynamicCount = CONVERSATION_DYNAMIC_COUNT;

    extract(&offsets);
    FreeLibrary(dll);
}
