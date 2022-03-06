#!/bin/bash
(
  cd compile/
  make
  scp xinu pfsense:/tftpboot/xinu
)
