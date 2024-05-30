#!/bin/bash

SCRIPT_DIR_PATH=$( dirname $0 )
echo $SCRIPT_DIR_PATH

SRC_DIR=$SCRIPT_DIR_PATH/src
PROTO_DIR=$SCRIPT_DIR_PATH/resource

protoc -I $PROTO_DIR --cpp_out=$SRC_DIR $PROTO_DIR/main.proto
protoc -I $PROTO_DIR --grpc_out=$SRC_DIR --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` $PROTO_DIR/main.proto
