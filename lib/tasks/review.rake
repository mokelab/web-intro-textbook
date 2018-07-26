require 'fileutils'
require 'rake/clean'

BOOK = ENV['REVIEW_BOOK'] || 'book'
BOOK_PDF = BOOK + '.pdf'
BOOK_EPUB = BOOK + '.epub'
CONFIG_FILE = ENV['REVIEW_CONFIG_FILE'] || 'config.yml'
CATALOG_FILE = ENV['REVIEW_CATALOG_FILE'] || 'catalog.yml'
WEBROOT = ENV['REVIEW_WEBROOT'] || 'webroot'
TEXTROOT = BOOK + '-text'
TOPROOT = BOOK + '-text'

def build(mode, chapter)
  sh "review-compile --target=#{mode} --footnotetext --stylesheet=style.css #{chapter} > tmp"
  mode_ext = { 'html' => 'html', 'latex' => 'tex', 'idgxml' => 'xml', 'top' => 'txt', 'plaintext' => 'txt' }
  FileUtils.mv 'tmp', chapter.gsub(/re\z/, mode_ext[mode])
end

def build_all(mode)
  sh "review-compile --target=#{mode} --footnotetext --stylesheet=style.css"
end

task default: :html_all

desc 'build html (Usage: rake build re=target.re)'
task :html do
  if ENV['re'].nil?
    puts 'Usage: rake build re=target.re'
    exit
  end
  build('html', ENV['re'])
end

desc 'build all html'
task :html_all do
  build_all('html')
end

desc 'preproc all'
task :preproc do
  Dir.glob('*.re').each do |file|
    sh "review-preproc --replace #{file}"
  end
end

desc 'generate PDF and EPUB file'
task all: %i[pdf epub]

desc 'generate PDF file'
task pdf: BOOK_PDF

desc 'generate static HTML file for web'
task web: WEBROOT

desc 'generate text file (without decoration)'
task plaintext: TEXTROOT do
  sh "review-textmaker -n #{CONFIG_FILE}"
end

desc 'generate (decorated) text file'
task text: TOPROOT do
  sh "review-textmaker #{CONFIG_FILE}"
end

desc 'generate EPUB file'
task epub: BOOK_EPUB

IMAGES = FileList['images/**/*']
OTHERS = ENV['REVIEW_DEPS'] || []
SRC = FileList['./**/*.re', '*.rb'] + [CONFIG_FILE, CATALOG_FILE] + IMAGES + FileList[OTHERS]
SRC_EPUB = FileList['*.css']
SRC_PDF = FileList['layouts/*.erb', 'sty/**/*.sty']

file BOOK_PDF => SRC + SRC_PDF do
  FileUtils.rm_rf [BOOK_PDF, BOOK, BOOK + '-pdf']
  sh "review-pdfmaker #{CONFIG_FILE}"
end

file BOOK_EPUB => SRC + SRC_EPUB do
  FileUtils.rm_rf [BOOK_EPUB, BOOK, BOOK + '-epub']
  sh "review-epubmaker #{CONFIG_FILE}"
end

file WEBROOT => SRC do
  FileUtils.rm_rf [WEBROOT]
  sh "review-webmaker #{CONFIG_FILE}"
end

file TEXTROOT => SRC do
  FileUtils.rm_rf [TEXTROOT]
end

CLEAN.include([BOOK, BOOK_PDF, BOOK_EPUB, BOOK + '-pdf', BOOK + '-epub', WEBROOT, 'images/_review_math', TEXTROOT])