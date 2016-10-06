function(page) {
    var regex = /<img[^>]*src="(content\/formfield_files\/[^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
