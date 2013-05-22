<div class="gigya-top-comments">
<?php
  // waiting on final design now
  print '<ul id="gigya_top_content">';
  $i = 0;
  $length = count($query_content);
  foreach ($query_content as $article) {
    $article_content = node_load($article['sid']);
    $node_path = 'node/' . $article['sid'];
    if ($article_content) {
      print '<li class="top_content_item">';
      print '<span class="comment_count">' . l($article['comment_count'], $node_path) . '</span>';
      print '<div class="meta"><span class="article_title">' . l($node_title, $node_path) . '</span>';
    }
    else {
      print '<li class="top_content_item">';
      print '<div class="meta"><span class="node_title">Content not found. Stream ID ' . $stream->sid . ' does not match any node ID\'s.</span>'; 
    }
    if ($i == $length - 1) {
      print '</div></li>';
    }
    else {
      print '</div></li><hr class="gigya_top_comments_item_divider" />';
    }
    $i++;
  }
  print '</ul>';
?>
</div>