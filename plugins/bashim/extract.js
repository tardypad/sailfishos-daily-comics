function(page) {
    var regex = /<img class="quote__img".+?src="([^"]*)"/;
    var match = regex.exec(page);
    return match[1];
}
