#include <lua.h>
#include <lauxlib.h>
#include <stdio.h>
extern lua_Number lua_tonumberx(lua_State *, int, int *);
static int add(lua_State *L){
    lua_Number a = lua_tonumberx(L, 1, NULL);
    printf("%d\n", lua_type(L, 1));
    lua_Number b = luaL_checknumber(L, 2);
    lua_Number c = a + b;
    lua_pushnumber(L, c);
    printf("%g + %g = %g\n", a, b, c);
    return 1;
}
static const struct luaL_Reg functions[] = {
    {"add", add},
    {NULL, NULL}
};
int luaopen_foo(lua_State *L){
    luaL_register(L, "foo", functions);
    return 1;
}
