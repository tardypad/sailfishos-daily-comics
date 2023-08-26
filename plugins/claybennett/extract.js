function(page) {
  var regex = /<img[^>]* data-srcset="([^ "]+)"/;
  var match = regex.exec(page);
  return match[1];
}
