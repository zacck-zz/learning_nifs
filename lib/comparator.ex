defmodule Comparator do
  @on_load :load_nifs

  def load_nifs do
    :erlang.load_nif('./src/fast_compare', 0)
  end

  def fast_comparison(_a, _b) do
    raise "NIF fast_comparison/2 not implemented"
  end
end
