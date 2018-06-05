#!/usr/bin/env ruby -wKU
#
# generate_docs.rb - Generate Documentation using Doxygen
#
# Copyright (c) 2018, Aaron Sutton <aaronjsutton@icloud.com>
#

`which doxygen`
unless $? == 0
  raise "Could not run doxygen program."
  exit 1
end

Dir.chdir "#{__dir__}/.."
system "doxygen"
