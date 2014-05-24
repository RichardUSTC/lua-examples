#include <lua.h>
#include <lauxlib.h>
#include <stdio.h>
#include <string.h>
void dump_stack(lua_State *L){
    int top = lua_gettop(L);
    printf("-----stack bottom------\n");
    int i;
    for(i=1; i<=top; i++){
        switch(lua_type(L, i)){
            case LUA_TNIL:
                printf("nil");
                break;
            case LUA_TNUMBER:
                printf("%g", lua_tonumber(L, i));
                break;
            case LUA_TBOOLEAN:
                printf(lua_toboolean(L, i)? "true": "false");
                break;
            case LUA_TSTRING:
                printf("'%s'", lua_tostring(L, i));
                break;
            default:
                printf("%s", lua_typename(L, i));
                break;
        }
        printf("\n");
    }
    printf("-----stack top ------\n");
}

int main(){
    lua_State *L = luaL_newstate();
    lua_pushboolean(L, 1);
    lua_pushboolean(L, 0);
    lua_pushnumber(L, 10);
    lua_pushnil(L);
    lua_pushstring(L, "hello");
    lua_pushlstring(L, "world", strlen("world"));
    dump_stack(L);
    lua_close(L);
    return 0;
}
