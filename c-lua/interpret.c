#include <lua.h>
#include <stdio.h>
#include <lauxlib.h>
#include <lualib.h>
#include <string.h>

#define BUFFER_SIZE 256
int main(){
    char buffer[BUFFER_SIZE];
    int error;
    lua_State * L = luaL_newstate();
    luaL_openlibs(L);

    while(fgets(buffer, BUFFER_SIZE, stdin) != NULL){
        error = luaL_loadbuffer(L, buffer, strlen(buffer), "line") ||
            lua_pcall(L, 0, 0, 0);
        if(error){
            fprintf(stderr, "lua error: %s\n", lua_tostring(L, -1));
            lua_pop(L, 1);
        }
    }
    lua_close(L);
    return 0;
}
