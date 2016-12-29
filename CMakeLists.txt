cmake_minimum_required(VERSION 3.5)
project(Parser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Lexer/lexer.cpp Lexer/lexer.h Parser/parse_table.cpp Parser/parse_table.h Parser/StateTraversal/parse_state_traversal.cpp Parser/StateTraversal/parse_state_traversal.h Parser/StateTraversal/parse_state_traversal_type.h Parser/grammar_rule.h Parser/State/grammar_state.cpp Parser/State/grammar_state.h Parser/State/grammar_state_connection.cpp Parser/State/grammar_state_connection.h Parser/AbstractSyntaxTree/abstract_syntax_tree_builder.cpp Parser/AbstractSyntaxTree/abstract_syntax_tree_builder.h Parser/parser.cpp Parser/parser.h Parser/Graph/edge_valued_graph.h Parser/AbstractSyntaxTree/abstract_syntax_tree_node.cpp Parser/AbstractSyntaxTree/abstract_syntax_tree_node.h Parser/AbstractSyntaxTree/abstract_syntax_tree.cpp Parser/AbstractSyntaxTree/abstract_syntax_tree.h)
add_executable(Parser ${SOURCE_FILES})