#!/usr/bin/env ruby -wU
#
# upload_docs.rb - Upload documentation to the server.
#
# Copyright (c) 2018, Aaron Sutton <aaronjsutton@icloud.com>
#

docs_path = "/var/www/github/deck"

Dir.chdir "#{__dir__}/.."

system "rsync -aruv docs/* docs@aaronjsutton.com:#{docs_path}"
