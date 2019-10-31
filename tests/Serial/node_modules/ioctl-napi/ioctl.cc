#include <node_api.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/ioctl.h>

// NAPI METHOD: napi_ioctl
napi_value napi_ioctl (napi_env env, napi_callback_info info) {
  int rc = 0;
  char code[4];
  size_t argc = 3;
  napi_value argv[3];
  napi_get_cb_info(env, info, &argc, argv, NULL, NULL);
  
  // Check if there are 3 arguments
  if (argc < 3) {
    napi_throw_error(
      env,
      NULL,
      "Wrong number of arguments. Expected 3");
    return NULL;
  }

  // Get fd value
  int32_t fd;
  if (napi_get_value_int32(env, argv[0], &fd) != napi_ok) {
    napi_throw_error(env, "EINVAL", "Expected number");
    return NULL;
  }

  // Get request value
  uint32_t request;
  if (napi_get_value_uint32(env, argv[1], &request) != napi_ok) { \
    napi_throw_error(env, "EINVAL", "Expected unsigned number"); \
    return NULL;
  }

  // Get argp value type (int or object)
  napi_valuetype valuetype2;
  napi_typeof(env, argv[2], &valuetype2);

  if (valuetype2 == napi_number) {
    // napi_number
    int32_t argp;
    if (napi_get_value_int32(env, argv[2], &argp) != napi_ok) {
      napi_throw_error(env, "EINVAL", "Expected number");
      return NULL;
    }
    rc = ioctl(fd, request, argp);
  } else {
    // napi_object
    void * argp;
    size_t argp_len;
    if (napi_get_buffer_info(env, argv[2], (void **) &argp, &argp_len) != napi_ok) {
      napi_throw_error(env, NULL, "napi_get_buffer_info() failed");
      return NULL;
    }
    rc = ioctl(fd, request, argp);
  }

  // return error if less than 0
  if (rc < 0) {
    sprintf(code, "%d", errno);
    napi_throw_error(env,code,(const char *) strerror(errno));
  }

  // retrun value
  napi_value return_int32;
  napi_create_int32(env, rc, &return_int32);
  return return_int32;
}

// NAPI INIT
static void napi_macros_init(napi_env env, napi_value exports);
napi_value napi_macros_init_wrap (napi_env env, napi_value exports) {
  napi_macros_init(env, exports);
  return exports;
} 
NAPI_MODULE(NODE_GYP_MODULE_NAME, napi_macros_init_wrap);
static void napi_macros_init (napi_env env, napi_value exports) {
  napi_value napi_ioctl_function;

  if ( 
    napi_create_function(
    env,
    "ioctl",
    NAPI_AUTO_LENGTH,
    napi_ioctl,
    NULL,
    &napi_ioctl_function) != napi_ok) 
  {
    napi_throw_error(env, NULL, "napi_create_function() failed!");
    return;
  }

  if (
    napi_set_named_property(
    env,
    exports,
    "ioctl",
    napi_ioctl_function) != napi_ok) 
  {
    napi_throw_error(env, NULL, "napi_set_named_property() failed!");
    return;
  }

}
